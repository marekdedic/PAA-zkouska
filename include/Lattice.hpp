#pragma once

class Lattice
{
public:
	Lattice() = delete;
	Lattice(const Lattice&) = delete;
	Lattice& operator=(const Lattice&) = delete;
	Lattice(const float xMin, const float yMin, const float xMax, const float yMax, const float tileSize);
	Row begin() const;
	Row end() const;

	const int getWidth() const;
	const int getHeight() const;
private:
	const float xMin;
	const float yMin;
	const float xMax;
	const float yMax;
	const float tileSize;
};
