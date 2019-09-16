#include "main.hpp"

vec StlToVec(const float* stlVec)
{
	return {*stlVec, *(stlVec + 1), *(stlVec + 2)};
}

vec vecMinus(vec a, vec b)
{
	return {a[0] - b[0], a[1] - b[1], a[2] - b[2]};
}
float scalarProduct(vec a, vec b)
{
	return a[0] * b[0] + a[1] * b[1] + a[2] * b[2];
}

float intersect(vec planePoint, vec linePoint, vec planeNormal, vec lineVec)
{
	float denominator{scalarProduct(lineVec, planeNormal)};
	if(denominator == 0)
	{
		return 0;
	}
	return scalarProduct(vecMinus(planePoint, linePoint), planeNormal);
}

int main()
{
	stl_reader::StlMesh mesh{"teapot.stl"};
	if(mesh.num_solids() > 1)
	{
		std::cerr << "Only STL files with 1 solid are supported" << std::endl;
		return -1;
	}
	const Lattice lattice{-15, -15, 15, 15, 1};
	for(auto row : lattice)
	{
		for(auto tile : row)
		{
			for(auto direction : tile)
			{
				std::array v{direction.getVec()};
				std::cout << v[0] << " " << v[1] << " " << v[2] << std::endl;
				for(size_t i{1};i < mesh.num_tris(); ++i)
				{
					std::cout << intersect(StlToVec(mesh.tri_corner_coords(i, 0)), tile.getCenter(), StlToVec(mesh.tri_normal(i)), direction.getVec()) << std::endl;
				}
			}
		}
	}
    std::cout << "Hello, World!" << mesh.num_solids() << std::endl;
    return 0;
}