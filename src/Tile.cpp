#include "main.hpp"

Direction Tile::begin() const
{
	return Direction{this, 0};
}

Direction Tile::end() const
{
	return Direction{this, 25};
}

const bool Tile::operator!=(const Tile& other) const
{
	return this->row != other.row || this->column != other.column;
}

Tile* Tile::operator++()
{
	++this->column;
	return this;
}

Tile& Tile::operator*()
{
	return *this;
}

const vec Tile::getCenter() const
{
	const Lattice* lattice{this->row->getLayer()->getLattice()};
	return {lattice->getXMin() + (row->getRow() + 0.5f) * lattice->getTileSize(), lattice->getYMin() + (column + 0.5f) * lattice->getTileSize(), lattice->getZMin() + (row->getLayer()->getLayer() + 0.5f) * lattice->getTileSize()};
}

Tile::Tile(const Row* row, const int column) : row{row}, column{column}
{}
