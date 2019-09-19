#pragma once

class LatticeInterface;
class Lattice;
class SubLattice;
class Column;

class Layer
{
public:
	Layer() = delete;
	Layer(const Layer&) = default;
	Layer& operator=(const Layer&) = delete;
	const bool operator!=(const Layer& other) const;
	Layer* operator++();
	Layer& operator*();
	Column* begin() const;
	Column* end() const;
	Column* next(Column* current) const;
	const LatticeInterface* getLattice() const;
	const int getLayer() const;
private:
	friend Lattice;
	friend SubLattice;

	std::vector<Column*> columns;
	const LatticeInterface* lattice;
	int layer;

	Layer(const LatticeInterface* lattice, const int layer);
};
