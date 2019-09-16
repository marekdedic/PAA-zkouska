#include "main.hpp"

const bool Layer::operator!=(const Layer& other) const
{
	return this->lattice != other.lattice || this->layer != other.layer;
}

Layer* Layer::operator++()
{
	++this->layer;
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
	return Column{this, this->lattice->getNumCols()};
}

const Lattice* Layer::getLattice() const
{
	return this->lattice;
}

const int Layer::getLayer() const
{
	return this->layer;
}

Layer::Layer(const Lattice* lattice, const int layer) : lattice{lattice}, layer{layer}
{}
