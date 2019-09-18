#include "main.hpp"

Lattice::Lattice(float xMin, float xMax, float yMin, float yMax, float zMin, float zMax, float tileSize) : xMin{xMin}, xMax{xMax}, yMin{yMin}, yMax{yMax}, zMin{zMin}, zMax{zMax}, tileSize{tileSize}
{
	auto check{[this](float min, float max, char dim)
	{
		double _{0};
		double decPart {modf((max - min) / this->tileSize, &_)};
		if(decPart > 0.5)
		{
			decPart = 1 - decPart;
		}
		if(decPart > 0.0001)
		{
			std::cerr << "The lattice doesn't have integer tile count in dimension " << dim << ".";
			std::cout << decPart << std::endl;
		}
	}};
	check(this->xMin, this->xMax, 'x');
	check(this->yMin, this->yMax, 'y');
	check(this->zMin, this->zMax, 'z');
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
	return this->tileSize;
}

const float Lattice::getXMin() const
{
	return this->xMin;
}

const float Lattice::getYMin() const
{
	return this->yMin;
}

const float Lattice::getZMin() const
{
	return this->zMin;
}

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

Layer Lattice::begin() const
{
	return Layer{this, 0};
}

Layer Lattice::end() const
{
	return Layer{this, this->getNumLayers()};
}
