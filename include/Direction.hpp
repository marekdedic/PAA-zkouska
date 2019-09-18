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
	static float linePlaneIntersection(vec planePoint, vec linePoint, vec planeNormal, vec lineVec);
	static bool pointInTriangle(stl_reader::StlMesh<float, unsigned int>* mesh, const size_t ti, vec point);
	void intersect(stl_reader::StlMesh<float, unsigned int>* mesh, const size_t ti);
	void intersectAll(stl_reader::StlMesh<float, unsigned int>* mesh);
	void write(std::vector<std::pair<vec, vec>>& output) const;
private:
	friend Tile;

	const Tile* tile;
	int direction;
	vec vector;
	float length;

	Direction(const Tile* tile, const int direction);
	void setLength();
	void setVec();
};
