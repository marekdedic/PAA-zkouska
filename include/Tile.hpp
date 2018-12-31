#pragma once

class RowSelector;

class Tile
{
	Direction operator[](const int index) const;
private:
	friend RowSelector;

	const RowSelector* row;
	const int column;

	Tile(const RowSelector* row, const int column);
};
