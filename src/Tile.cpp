#include "main.hpp"

Direction* Tile::begin() const
{
	return new Direction{this, 0};
}

Direction* Tile::end() const
{
	return new Direction{this, 25};
}

Tile::Tile(const Row* row, const int column) : row{row}, column{column}
{}
