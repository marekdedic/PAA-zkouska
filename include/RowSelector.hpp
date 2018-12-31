#pragma once

class Lattice;

class RowSelector
{
public:
	Tile operator[](const int index) const;
private:
	friend Lattice;

	const Lattice* lattice;
	const int row;

	RowSelector(const Lattice* lattice, const int row);
};
