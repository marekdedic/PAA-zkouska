#pragma once

class Lattice;
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
	Column begin() const;
	Column end() const;
	const Lattice* getLattice() const;
	const int getLayer() const;
private:
	friend Lattice;

	const Lattice* lattice;
	int layer;

	Layer(const Lattice* lattice, const int layer);
};
