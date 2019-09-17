#pragma once

class Tile;

class Direction
{
public:
	Direction() = delete;
	Direction(const Direction&) = default;
	Direction& operator=(const Direction&) = delete;
	const bool operator!=(const Direction& other) const;
	Direction* operator++();
	Direction& operator*();

	const vec getVec() const;
	static vec stlToVec(const float* stlVec);
	static vec vecPlus(vec a, vec b);
	static vec vecMinus(vec a, vec b);
	static vec vecTimes(float a, vec b);
	static float scalarProduct(vec a, vec b);
	static float linePlaneIntersection(vec planePoint, vec linePoint, vec planeNormal, vec lineVec);
	void intersect(stl_reader::StlMesh<float, unsigned int>* mesh, const size_t ti);
	void write(vtkSmartPointer<vtkPoints> points, vtkSmartPointer<vtkCellArray> lines) const;
private:
	friend Tile;
	static unsigned int pointCounter;

	const Tile* tile;
	int direction;
	float length;

	Direction(const Tile* tile, const int direction);
};
