#include "main.hpp"

const bool Row::operator!=(const Row& other) const
{
	return this->layer != other.layer || this->row != other.row;
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

Tile Row::begin() const
{
	return Tile{this, 0};
}

Tile Row::end() const
{
	return Tile{this, this->layer->getLattice()->getNumRows()};
}

const Layer* Row::getLayer() const
{
	return this->layer;
}

const int Row::getRow() const
{
	return this->row;
}

Row::Row(const Layer* layer, const int index) : layer{layer}, row{index}
{}
