#include "main.hpp"

Tile Row::begin() const
{
	return Tile{this, 0};
}

Tile Row::end() const
{
	return Tile{this, this->lattice->getNumRows()};
}

const bool Row::operator!=(const Row& other) const
{
	return this->lattice != other.lattice || this->row != other.row;
}

Row* Row::operator++()
{
	++this->row;
	return this;
}

Row& Row::operator*()
{
	return *this;
}

const Lattice* Row::getLattice() const
{
	return this->lattice;
}

Row::Row(const Lattice* lattice, const int index) : lattice{lattice}, row{index}
{}
