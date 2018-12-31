#pragma once

class Tile;

class Direction
{
private:
	friend Tile;

	const Tile* tile;
	const int direction;

	Direction(const Tile* tile, const int direction);
};
