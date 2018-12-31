#pragma once

class Lattice;

class Row
{
public:
	Tile operator[](const int index) const;
private:
	friend Lattice;

	const Lattice* lattice;
	const int row;

	Row(const Lattice* lattice, const int row);
};
