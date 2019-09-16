#pragma once

class Layer;

class Column
{
public:
	Column() = delete;
	Column(const Column&) = default;
	Column& operator=(const Column&) = delete;
	const bool operator!=(const Column& other) const;
	Column* operator++();
	Column& operator*();
	Tile begin() const;
	Tile end() const;
	const Layer* getLayer() const;
	const int getColumn() const;
private:
	friend Layer;

	const Layer* layer;
	int column;

	Column(const Layer* lattice, const int column);
};
