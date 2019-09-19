#pragma once

class Lattice;

class SubLattice : public LatticeInterface
{
public:
	SubLattice() = delete;
	SubLattice(const SubLattice&) = delete;
	SubLattice& operator=(const SubLattice&) = delete;
	SubLattice(const Lattice* lattice, const int xMin, const int xMax, const int yMin, const int yMax, const int zMin, const int zMax);
	Layer* begin() const;
	Layer* end() const;
	Layer* next(Layer* current) const;

	virtual const int getNumRows() const; // Rows along X
	virtual const int getNumCols() const; // Cols along Y
	virtual const int getNumLayers() const; // Layers along Z
	virtual const float getXMin() const;
	virtual const float getYMin() const;
	virtual const float getZMin() const;
	virtual const float getTileSize() const;
private:
	const Lattice* lattice;
	const int xMin;
	const int xMax;
	const int yMin;
	const int yMax;
	const int zMin;
	const int zMax;
};
