#include "main.hpp"

Lattice::Lattice(float xMin, float yMin, float xMax, float yMax, float tileSize) : xMin{xMin}, yMin{yMin}, xMax{xMax}, yMax{yMax}, tileSize{tileSize}
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
}

const int Lattice::getNumCols() const
{
	return static_cast<int>(round(this->xMax - this->xMin / this->tileSize));
}

const int Lattice::getNumRows() const
{
	return static_cast<int>(round(this->yMax - this->yMin / this->tileSize));
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

Row Lattice::begin() const
{
	return Row{this, 0};
}

Row Lattice::end() const
{
	return Row{this, this->getNumCols()};
}
