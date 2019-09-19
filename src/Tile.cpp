#include "main.hpp"

Direction* Tile::begin() const
{
	return directions.front();
}

Direction* Tile::end() const
{
	return directions.back();
}

Direction* Tile::next(Direction *current) const
{
	if(current == end())
	{
		return nullptr;
	}
	return *std::next(std::find(directions.begin(), directions.end(), current));
}

const bool Tile::operator!=(const Tile& other) const
{
	return column != other.column || tile != other.tile;
}

Tile* Tile::operator++()
{
	++tile;
	setCenter();
	return this;
}

Tile& Tile::operator*()
{
	return *this;
}

const Column* Tile::getColumn() const
{
	return column;
}

const vec Tile::getCenter() const
{
	return center;
}

Tile::Tile(const Column* column, const int tile) : column{column}, tile{tile}, center{0, 0, 0}, directions{}
{
	setCenter();
	directions.reserve(26);
	for(int i{0}; i < 26; ++i)
	{
		directions.emplace_back(new Direction{this, i});
	}
}

void Tile::setCenter()
{
	const LatticeInterface* lattice{column->getLayer()->getLattice()};
	center =  {lattice->getXMin() + (tile + 0.5f) * lattice->getTileSize(), lattice->getYMin() + (column->getColumn() + 0.5f) * lattice->getTileSize(), lattice->getZMin() + (column->getLayer()->getLayer() + 0.5f) * lattice->getTileSize()};
}
