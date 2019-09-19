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

Tile* Column::begin() const
{
	return tiles.front();
}

Tile* Column::end() const
{
	return tiles.back();
}

Tile* Column::next(Tile *current) const
{
	if(current == end())
	{
		return nullptr;
	}
	return *std::next(std::find(tiles.begin(), tiles.end(), current));
}

const Layer* Column::getLayer() const
{
	return layer;
}

const int Column::getColumn() const
{
	return column;
}

Column::Column(const Layer* layer, const int column) : layer{layer}, column{column}, tiles{}
{
	tiles.reserve(layer->getLattice()->getNumRows());
	for(int i{0}; i < layer->getLattice()->getNumRows(); ++i)
	{
		tiles.emplace_back(new Tile{this, i});
	}
}
