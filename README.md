# PAA-zkouska

Parallel intersection computation for the lattice Boltzmann method

## The task

The task is to load an [STL file](https://en.wikipedia.org/wiki/STL_(file_format)). Then, create a 3D lattice with an "arrow" from the center of each tile to all of its corners, all of the centers of its edges and all of the centers of its faces. Then, each arrow is shortened so that it doesn't intersect the mesh from the STL file.

## The environment

The solution was implemented using C++ in 4 ways: a baseline implementation to serve as a verification, an optimised implementation based on the feedback from a profiler and then 2 versions of a multi-threaded implementation.

As a test mesh, the [Utah teapot](https://en.wikipedia.org/wiki/Utah_teapot) was used. All tests were run on a Lenoo T460 running Debian Linux. The performance was measured using `time` as implemented in the Z shell.

## Implementation

### Baseline

This is the basic implementation of the algorithm, using brute force. That is, for each arrow and each triangle, the intersection of the line defined by the arrow and the plane defined by the triangle is calculated. If this intersection lies in the actual triangle and inside the arrow, it is used as a new arrow endpoint. Running this program gives the following result:

```sh
./PAA  1430,10s user 0,05s system 99% cpu 23:50,28 total
```

The program ran for around 24 minutes computing a 20 × 20 × 20 lattice intersection.

### Optimised

The baseline implementation was profiled using Linux perf in combination with the CLion profiling utilities, which turn perf output into a flamegraph for easier use. Most of the time was spent on the intersection computation, as would be expected. However, aside from basic algebra, there were 3 functions, which could be easily optimised:

- the `Direction::getVec` function is supposed to return a unit length vector in the direction of the particular arrow. In the baseline implementation, this vector is returned by a `switch` statement upon each call. The call was optimised by saving this vector on object creation and then just returning it.
- the `Tile::getCenter` function was similarily computing the center of the tile on each call. Again, the result was pre-computed in the constructor.
- the `Direction::pointInTriangle` function was optimised by returning a negative result earlier if possible, removing some unnecessary computation.

The precise optimisations can be seen in the [diff view](https://github.com/marekdedic/PAA-zkouska/compare/baseline...optimised).

The resulting code gives the folloeing results:

```sh
./PAA  709,58s user 0,06s system 99% cpu 11:49,67 total
```

As can be seen, the program went from running for 24 minutes to around 12 minutes, so the optimisations alone cut the runtime by half.

# Simple multi-threaded algorithm

A naive implementation of parallelism was implemented - each tile being computed on a separate thread. This implementation requires using a mutex for writing the output data, but as we saw in the profiler, most of the runtime is spent computing intersections, which is parallelisable without any synchronization, so the mutex shouldn't be a big issue.

The precise changes can be seen in the [diff view](https://github.com/marekdedic/PAA-zkouska/compare/optimised...simple-multi-thread).

The resulting code gives the folloeing results:

```sh
./PAA  1093,71s user 0,65s system 394% cpu 4:37,13 total
```
The total run of the program was around 4 and a half minutes, so approximately 3 times faster than the sequential code. Given that the test machine has a 4-core processor, this gives the effectivity at around 64%.

# Efficient multi-threaded algorithm

./PAA  1117,53s user 0,26s system 376% cpu 4:56,93 total
