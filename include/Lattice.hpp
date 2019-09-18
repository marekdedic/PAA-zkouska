#pragma once

class Lattice
{
public:
	Lattice() = delete;
	Lattice(const Lattice&) = delete;
	Lattice& operator=(const Lattice&) = delete;
	Lattice(const float xMin, const float xMax, const float yMin, const float yMax, const float zMin, const float zMax, const float tileSize);
	Layer begin() const;
	Layer end() const;

	const int getNumRows() const; // Rows along X
	const int getNumCols() const; // Cols along Y
	const int getNumLayers() const; // Layers along Z
	const float getTileSize() const;
	const float getXMin() const;
	const float getYMin() const;
	const float getZMin() const;
private:
	const float xMin;
	const float xMax;
	const float yMin;
	const float yMax;
	const float zMin;
	const float zMax;
	const float tileSize;

	void checkDimension(const float min, const float max, const char dim) const;
};
