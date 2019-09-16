#pragma once

class Layer;

class Row
{
public:
	Row() = delete;
	Row(const Row&) = default;
	Row& operator=(const Row&) = delete;
	const bool operator!=(const Row& other) const;
	Row* operator++();
	Row& operator*();
	Tile begin() const;
	Tile end() const;
	const Layer* getLayer() const;
	const int getRow() const;
private:
	friend Layer;

	const Layer* layer;
	int row;

	Row(const Layer* lattice, const int row);
};
