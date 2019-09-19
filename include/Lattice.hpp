#pragma once

class Lattice : public LatticeInterface
{
public:
	Lattice() = delete;
	Lattice(const Lattice&) = delete;
	Lattice& operator=(const Lattice&) = delete;
	Lattice(const float xMin, const float xMax, const float yMin, const float yMax, const float zMin, const float zMax, const float tileSize);
	Layer* begin() const;
	Layer* end() const;
	Layer* next(Layer* current) const;

	virtual const int getNumRows() const; // Rows along X
	virtual const int getNumCols() const; // Cols along Y
	virtual const int getNumLayers() const; // Layers along Z
	virtual const float getTileSize() const;
	virtual const float getXMin() const;
	virtual const float getYMin() const;
	virtual const float getZMin() const;
	//SubLattice* subLattice(int i, int total) const;
	SubLattice* intersect(std::pair<vec, vec>& aabb) const;
private:
	friend SubLattice;

	std::vector<Layer*> layers;
	const float xMin;
	const float xMax;
	const float yMin;
	const float yMax;
	const float zMin;
	const float zMax;
	const float tileSize;

	void checkDimension(const float min, const float max, const char dim) const;
};
