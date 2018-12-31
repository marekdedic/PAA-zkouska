#pragma once

class Row;

class Tile
{
public:
	Direction* begin() const;
	Direction* end() const;
private:
	friend Row;

	const Row* row;
	const int column;

	Tile(const Row* row, const int column);
};
