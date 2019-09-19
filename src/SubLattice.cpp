#include "main.hpp"

SubLattice::SubLattice(const Lattice *lattice, const int xMin, const int xMax, const int yMin, const int yMax, const int zMin, const int zMax): lattice{lattice}, xMin{xMin}, xMax{xMax}, yMin{yMin}, yMax{yMax}, zMin{zMin}, zMax{zMax}
{}

Layer* SubLattice::begin() const
{
	return lattice->layers.at(xMin);
}

Layer* SubLattice::end() const
{
	return lattice->layers.at(xMax);
}

Layer* SubLattice::next(Layer *current) const
{
	return lattice->next(current);
}

const int SubLattice::getNumRows() const
{
	return xMax - xMin;
}
const int SubLattice::getNumCols() const
{
	return yMax - yMin;
}
const int SubLattice::getNumLayers() const
{
	return zMax - zMin;
}
const float SubLattice::getXMin() const
{
	return lattice->getXMin() + xMin * getTileSize();
}
const float SubLattice::getYMin() const
{
	return lattice->getYMin() + yMin * getTileSize();
}
const float SubLattice::getZMin() const
{
	return lattice->getZMin() + zMin * getTileSize();
}
const float SubLattice::getTileSize() const
{
	return lattice->getTileSize();
}
