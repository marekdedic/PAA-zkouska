#pragma once

class Lattice
{
public:
	const float xMin;
	const float yMin;
	const float xMax;
	const float yMax;
	const float tileSize;

	Lattice(float xMin, float yMin, float xMax, float yMax, float tileSize);
	const int getWidth() const;
	const int getHeight() const;
};
