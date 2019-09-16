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

Row Layer::begin() const
{
	return Row{this, 0};
}

Row Layer::end() const
{
	return Row{this, this->lattice->getNumRows()};
}

const Lattice* Layer::getLattice() const
{
	return this->lattice;
}

Layer::Layer(const Lattice* lattice, const int index) : lattice{lattice}, layer{index}
{}
