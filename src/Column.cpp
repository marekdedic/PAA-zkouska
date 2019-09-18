#include "main.hpp"

const bool Column::operator!=(const Column& other) const
{
	return layer != other.layer || column != other.column;
}

Column* Column::operator++()
{
	++column;
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
	return Tile{this, layer->getLattice()->getNumRows()};
}

const Layer* Column::getLayer() const
{
	return layer;
}

const int Column::getColumn() const
{
	return column;
}

Column::Column(const Layer* layer, const int column) : layer{layer}, column{column}
{}
