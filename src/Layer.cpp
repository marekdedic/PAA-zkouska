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

Column* Layer::begin() const
{
	return columns.front();
}

Column* Layer::end() const
{
	return columns.back();
}

Column* Layer::next(Column *current) const
{
	if(current == end())
	{
		return nullptr;
	}
	return *std::next(std::find(columns.begin(), columns.end(), current));
}

const LatticeInterface* Layer::getLattice() const
{
	return lattice;
}

const int Layer::getLayer() const
{
	return layer;
}

Layer::Layer(const LatticeInterface* lattice, const int layer) : lattice{lattice}, layer{layer}, columns{}
{
	columns.reserve(lattice->getNumCols());
	for(int i{0}; i < lattice->getNumCols(); ++i)
	{
		columns.emplace_back(new Column{this, i});
	}
}
