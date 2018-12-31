#pragma once

class Tile;

class Direction
{
public:
	const std::array<float, 3> getVec() const;
private:
	friend Tile;

	const Tile* tile;
	const int direction;

	Direction(const Tile* tile, const int direction);
};
