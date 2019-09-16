#include "main.hpp"

const bool Column::operator!=(const Column& other) const
{
	return this->layer != other.layer || this->column != other.column;
}

Column* Column::operator++()
{
	++this->column;
	return this;
}

Column& Column::operator*()
{
	return *this;
}

Tile Column::begin() const
{
	return Tile{this, 0};
}

Tile Column::end() const
{
	return Tile{this, this->layer->getLattice()->getNumRows()};
}

const Layer* Column::getLayer() const
{
	return this->layer;
}

const int Column::getColumn() const
{
	return this->column;
}

Column::Column(const Layer* layer, const int column) : layer{layer}, column{column}
{}
