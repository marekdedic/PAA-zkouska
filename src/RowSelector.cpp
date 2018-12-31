#include "main.hpp"

Tile RowSelector::operator[](int index) const
{
	return Tile{this, index};
}

RowSelector::RowSelector(const Lattice* lattice, const int index) : lattice{lattice}, row{index}
{}
