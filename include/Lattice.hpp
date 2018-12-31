#pragma once

class Lattice
{
public:
	Lattice(const float xMin, const float yMin, const float xMax, const float yMax, const float tileSize);
	const int getWidth() const;
	const int getHeight() const;
	Row* begin() const;
	Row* end() const;
private:
	const float xMin;
	const float yMin;
	const float xMax;
	const float yMax;
	const float tileSize;
};
