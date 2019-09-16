#pragma once

class Row;

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
	friend Row;

	const Row* row;
	int column;

	Tile(const Row* row, const int column);
};
