#include "main.hpp"

Lattice::Lattice(float xMin, float xMax, float yMin, float yMax, float zMin, float zMax, float tileSize) : layers{}, xMin{xMin}, xMax{xMax}, yMin{yMin}, yMax{yMax}, zMin{zMin}, zMax{zMax}, tileSize{tileSize}
{
	checkDimension(xMin, xMax, 'x');
	checkDimension(yMin, yMax, 'y');
	checkDimension(zMin, zMax, 'z');

	layers.reserve(getNumLayers());
	for(int i{0}; i < getNumLayers(); ++i)
	{
		layers.emplace_back(new Layer{this, i});
	}
}

const int Lattice::getNumRows() const
{
	return static_cast<int>(round((xMax - xMin) / tileSize));
}

const int Lattice::getNumCols() const
{
	return static_cast<int>(round((yMax - yMin) / tileSize));
}

const int Lattice::getNumLayers() const
{
	return static_cast<int>(round((zMax - zMin) / tileSize));
}

const float Lattice::getTileSize() const
{
	return tileSize;
}

const float Lattice::getXMin() const
{
	return xMin;
}

const float Lattice::getYMin() const
{
	return yMin;
}

const float Lattice::getZMin() const
{
	return zMin;
}

/*
SubLattice* Lattice::subLattice(int i, int total) const
{
	if((xMax - xMin) >= (yMax - yMin) and (xMax - xMin) >= (zMax - zMin))
	{
		float sxMin{xMin + tileSize * round(round((xMax - xMin) / tileSize) / total) * i};
		float sxMax{i == total - 1 ? xMax : xMin + tileSize * round(round((xMax - xMin) / tileSize) / total) * (i + 1)};
		return new SubLattice{this, sxMin, sxMax, yMin, yMax, zMin, zMax};
	}
	if((yMax - yMin) >= (zMax - zMin))
	{
		float syMin{yMin + tileSize * round(round((yMax - yMin) / tileSize) / total) * i};
		float syMax{i == total - 1 ? yMax : yMin + tileSize * round(round((yMax - yMin) / tileSize) / total) * (i + 1)};
		return new SubLattice{this, xMin, xMax, syMin, syMax, zMin, zMax};
	}
	float szMin{zMin + tileSize * round(round((zMax - zMin) / tileSize) / total) * i};
	float szMax{i == total - 1 ? zMax : zMin + tileSize * round(round((zMax - zMin) / tileSize) / total) * (i + 1)};
	return new SubLattice{this, xMin, xMax, yMin, yMax, szMin, szMax};
}
 */

SubLattice* Lattice::intersect(std::pair<vec, vec>& aabb) const
{
	int sxMin{static_cast<int>(floor((aabb.first[0] - xMin) / tileSize))};
	int syMin{static_cast<int>(floor((aabb.first[1] - yMin) / tileSize))};
	int szMin{static_cast<int>(floor((aabb.first[2] - zMin) / tileSize))};
	int sxMax{static_cast<int>(floor((aabb.second[0] - xMin) / tileSize))};
	int syMax{static_cast<int>(floor((aabb.second[1] - yMin) / tileSize))};
	int szMax{static_cast<int>(floor((aabb.second[2] - zMin) / tileSize))};
	return new SubLattice{this, sxMin, sxMax, syMin, syMax, szMin, szMax};
}

Layer* Lattice::begin() const
{
	return layers.front();
}

Layer* Lattice::end() const
{
	return layers.back();
}

Layer* Lattice::next(Layer *current) const
{
	if(current == end())
	{
		return nullptr;
	}
	return *std::next(std::find(layers.begin(), layers.end(), current));
}

void Lattice::checkDimension(const float min, const float max, const char dim) const
{
	double intpart{0};
	double decPart{modf((max - min) / tileSize, &intpart)};
	if(decPart > 0.5)
	{
		decPart = 1 - decPart;
	}
	if(decPart > 0.0001)
	{
		std::cerr << "The lattice doesn't have integer tile count in dimension " << dim << ".";
	}
}
