#pragma once

class Lattice;

class SubLattice : public LatticeInterface
{
public:
	SubLattice() = delete;
	SubLattice(const SubLattice&) = delete;
	SubLattice& operator=(const SubLattice&) = delete;
	SubLattice(const Lattice* lattice, const float xMin, const float xMax, const float yMin, const float yMax, const float zMin, const float zMax);
	Layer begin() const;
	Layer end() const;

	virtual const int getNumRows() const; // Rows along X
	virtual const int getNumCols() const; // Cols along Y
	virtual const int getNumLayers() const; // Layers along Z
	virtual const float getXMin() const;
	virtual const float getYMin() const;
	virtual const float getZMin() const;
	virtual const float getTileSize() const;
private:
	const Lattice* lattice;
	const float xMin;
	const float xMax;
	const float yMin;
	const float yMax;
	const float zMin;
	const float zMax;
};
