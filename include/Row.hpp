#pragma once

class Lattice;

class Row
{
public:
	Tile* begin() const;
	Tile* end() const;
private:
	friend Lattice;

	const Lattice* lattice;
	const int row;

	Row(const Lattice* lattice, const int row);
};
