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
	Direction* begin() const;
	Direction* end() const;
	Direction* next(Direction* current) const;

	const Column* getColumn() const;
	const vec getCenter() const;
private:
	friend Column;

	std::vector<Direction*> directions;
	const Column* column;
	int tile;
	vec center;

	Tile(const Column* column, const int tile);
	void setCenter();
};
