#pragma once

class RowSelector;

class Tile
{

private:
	friend RowSelector;

	const RowSelector* row;
	const int column;

	Tile(const RowSelector* row, const int column);
};
