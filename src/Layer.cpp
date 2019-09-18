#include "main.hpp"

const bool Layer::operator!=(const Layer& other) const
{
	return lattice != other.lattice || layer != other.layer;
}

Layer* Layer::operator++()
{
	++layer;
	return this;
}

Layer& Layer::operator*()
{
	return *this;
}

Column Layer::begin() const
{
	return Column{this, 0};
}

Column Layer::end() const
{
	return Column{this, lattice->getNumCols()};
}

const Lattice* Layer::getLattice() const
{
	return lattice;
}

const int Layer::getLayer() const
{
	return layer;
}

Layer::Layer(const Lattice* lattice, const int layer) : lattice{lattice}, layer{layer}
{}
