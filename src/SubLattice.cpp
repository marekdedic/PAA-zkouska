#include "main.hpp"

SubLattice::SubLattice(const Lattice *lattice, const float xMin, const float xMax, const float yMin, const float yMax, const float zMin, const float zMax): lattice{lattice}, xMin{xMin}, xMax{xMax}, yMin{yMin}, yMax{yMax}, zMin{zMin}, zMax{zMax}
{}

Layer SubLattice::begin() const
{
	return Layer{this, 0};
}

Layer SubLattice::end() const
{
	return Layer{this, this->getNumLayers()};
}

const int SubLattice::getNumRows() const
{
	return static_cast<int>(round((xMax - xMin) / lattice->getTileSize()));
}
const int SubLattice::getNumCols() const
{
	return static_cast<int>(round((yMax - yMin) / lattice->getTileSize()));
}
const int SubLattice::getNumLayers() const
{
	return static_cast<int>(round((zMax - zMin) / lattice->getTileSize()));
}
const float SubLattice::getXMin() const
{
	return xMin;
}
const float SubLattice::getYMin() const
{
	return yMin;
}
const float SubLattice::getZMin() const
{
	return zMin;
}
const float SubLattice::getTileSize() const
{
	return lattice->getTileSize();
}
