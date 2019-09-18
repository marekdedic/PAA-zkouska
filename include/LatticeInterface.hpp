#pragma once

class LatticeInterface {
public:
	virtual const int getNumRows() const = 0; // Rows along X
	virtual const int getNumCols() const = 0; // Cols along Y
	virtual const int getNumLayers() const = 0; // Layers along Z
	virtual const float getXMin() const = 0;
	virtual const float getYMin() const = 0;
	virtual const float getZMin() const = 0;
	virtual const float getTileSize() const = 0;
};
