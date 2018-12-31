#pragma once

class Row;

class Tile
{
	Direction operator[](const int index) const;
private:
	friend Row;

	const Row* row;
	const int column;

	Tile(const Row* row, const int column);
};
