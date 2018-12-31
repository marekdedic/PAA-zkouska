#include "main.hpp"

Tile* Row::begin() const
{
	return new Tile{this, 0};
}

Tile* Row::end() const
{
	return new Tile{this, this->lattice->getHeight()};
}

Row::Row(const Lattice* lattice, const int index) : lattice{lattice}, row{index}
{}
