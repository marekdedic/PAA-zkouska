#pragma once

class Lattice;
class Row;

class Layer
{
public:
	Layer() = delete;
	Layer(const Layer&) = default;
	Layer& operator=(const Layer&) = delete;
	const bool operator!=(const Layer& other) const;
	Layer* operator++();
	Layer& operator*();
	Row begin() const;
	Row end() const;
	const Lattice* getLattice() const;
private:
	friend Lattice;

	const Lattice* lattice;
	int layer;

	Layer(const Lattice* lattice, const int layer);
};
