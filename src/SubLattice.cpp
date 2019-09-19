#include "main.hpp"

SubLattice::SubLattice(const Lattice *lattice, const int xMin, const int xMax, const int yMin, const int yMax, const int zMin, const int zMax): lattice{lattice}, xMin{xMin}, xMax{xMax}, yMin{yMin}, yMax{yMax}, zMin{zMin}, zMax{zMax}
{}

SubLayer* SubLattice::begin() const
{
	return new SubLayer{lattice->layers.at(xMin), yMin, yMax, zMin, zMax};
}

SubLayer* SubLattice::end() const
{
	return new SubLayer{lattice->layers.at(xMax), yMin, yMax, zMin, zMax};
}

SubLayer* SubLattice::next(SubLayer *current) const
{
	if(lattice->next(current->layer) == nullptr)
	{
		return nullptr;
	}
	return new SubLayer{lattice->next(current->layer), yMin, yMax, zMin, zMax};
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
