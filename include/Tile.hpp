#pragma once

class Row;

class Tile
{
public:
	Tile() = delete;
	Tile(const Tile&) = default;
	Tile& operator=(const Tile&) = delete;
	Direction begin() const;
	Direction end() const;
	const bool operator!=(const Tile& other) const;
	Tile* operator++();
	Tile& operator*();
private:
	friend Row;

	const Row* row;
	int column;

	Tile(const Row* row, const int column);
};
