#include "main.hpp"

Direction Tile::operator[](const int index) const
{
	return Direction{this, index};
}

Tile::Tile(const Row* row, const int column) : row{row}, column{column}
{}
