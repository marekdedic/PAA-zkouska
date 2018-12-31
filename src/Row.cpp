#include "main.hpp"

Tile Row::operator[](int index) const
{
	return Tile{this, index};
}

Row::Row(const Lattice* lattice, const int index) : lattice{lattice}, row{index}
{}
