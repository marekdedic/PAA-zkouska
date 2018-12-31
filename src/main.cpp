#include "main.hpp"

int main()
{
	stl_reader::StlMesh mesh{"teapot.stl"};
	if(mesh.num_solids() > 1)
	{
		std::cerr << "Only STL files with 1 solid are supported" << std::endl;
		return -1;
	}
	const Lattice lattice{-15, -15, 15, 15, 1};
    std::cout << "Hello, World!" << mesh.num_solids() << std::endl;
    return 0;
}