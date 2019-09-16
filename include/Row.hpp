#pragma once

class Lattice;

class Row
{
public:
	Row() = delete;
	Row(const Row&) = default;
	Row& operator=(const Row&) = delete;
	const bool operator!=(const Row& other) const;
	Row* operator++();
	Row& operator*();
	Tile begin() const;
	Tile end() const;
	const Lattice* getLattice() const;
private:
	friend Lattice;

	const Lattice* lattice;
	int row;

	Row(const Lattice* lattice, const int row);
};
