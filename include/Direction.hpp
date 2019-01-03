#pragma once

class Tile;

class Direction
{
public:
	Direction() = delete;
	Direction(const Direction&) = default;
	Direction& operator=(const Direction&) = delete;
	const bool operator!=(const Direction& other) const;
	Direction* operator++();
	Direction& operator*();

	const vec getVec() const;
private:
	friend Tile;

	const Tile* tile;
	int direction;

	Direction(const Tile* tile, const int direction);
};
