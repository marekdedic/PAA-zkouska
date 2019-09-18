# PAA-zkouska

Parallel intersection computation for the lattice Boltzmann method

# Baseline

./PAA  1430,10s user 0,05s system 99% cpu 23:50,28 total

# Optimised

./PAA  709,58s user 0,06s system 99% cpu 11:49,67 total

# Simple multi-threaded algorithm

./PAA  1093,71s user 0,65s system 394% cpu 4:37,13 total

# Efficient multi-threaded algorithm

./PAA  1117,53s user 0,26s system 376% cpu 4:56,93 total
