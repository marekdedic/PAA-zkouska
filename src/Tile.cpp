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
	return {this->row->getLattice()->getXMin() + (column + 0.5f) * this->row->getLattice()->getTileSize(), 1, 0}; // TODO: Z
}

Tile::Tile(const Row* row, const int column) : row{row}, column{column}
{}
