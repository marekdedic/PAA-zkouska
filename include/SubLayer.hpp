#pragma once

class SubLattice;

class SubLayer {
public:
	SubLayer() = delete;
	SubLayer(const SubLayer&) = delete;
	SubLayer& operator=(const SubLayer&) = delete;
	SubLayer(Layer* layer, int yMin, int yMax, int zMin, int zMax);
	Column* begin() const;
	Column* end() const;
	Column* next(Column* current) const;
private:
	friend SubLattice;

	Layer* layer;
	int yMin;
	int yMax;
	int zMin;
	int zMax;
};
