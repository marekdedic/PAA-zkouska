#pragma once

class Column;

class Tile
{
public:
	Tile() = delete;
	Tile(const Tile&) = default;
	Tile& operator=(const Tile&) = delete;
	const bool operator!=(const Tile& other) const;
	Tile* operator++();
	Tile& operator*();
	Direction begin() const;
	Direction end() const;

	const vec getCenter() const;
private:
	friend Column;

	const Column* column;
	int tile;

	Tile(const Column* column, const int tile);
};
