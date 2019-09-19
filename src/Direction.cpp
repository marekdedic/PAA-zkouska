#include "main.hpp"

const bool Direction::operator!=(const Direction& other) const
{
	return tile != other.tile || direction != other.direction || length != other.length;
}

Direction* Direction::operator++()
{
	++direction;
	setLength();
	return this;
}

Direction& Direction::operator*()
{
	return *this;
}

const vec Direction::getVec() const
{
	vec ret{0, 0, 0};
	switch(direction)
	{
		case 0:
			ret = {-1, -1, -1};
			break;
		case 1:
			ret = {-1, -1, 0};
			break;
		case 2:
			ret = {-1, -1, 1};
			break;
		case 3:
			ret = {-1, 0, -1};
			break;
		case 4:
			ret = {-1, 0, 0};
			break;
		case 5:
			ret = {-1, 0, 1};
			break;
		case 6:
			ret = {-1, 1, -1};
			break;
		case 7:
			ret = {-1, 1, 0};
			break;
		case 8:
			ret = {-1, 1, 1};
			break;
		case 9:
			ret = {0, -1, -1};
			break;
		case 10:
			ret = {0, -1, 0};
			break;
		case 11:
			ret = {0, -1, 1};
			break;
		case 12:
			ret = {0, 0, -1};
			break;
		case 13:
			ret = {0, 0, 1};
			break;
		case 14:
			ret = {0, 1, -1};
			break;
		case 15:
			ret = {0, 1, 0};
			break;
		case 16:
			ret = {0, 1, 1};
			break;
		case 17:
			ret = {1, -1, -1};
			break;
		case 18:
			ret = {1, -1, 0};
			break;
		case 19:
			ret = {1, -1, 1};
			break;
		case 20:
			ret = {1, 0, -1};
			break;
		case 21:
			ret = {1, 0, 0};
			break;
		case 22:
			ret = {1, 0, 1};
			break;
		case 23:
			ret = {1, 1, -1};
			break;
		case 24:
			ret = {1, 1, 0};
			break;
		case 25:
			ret = {1, 1, 1};
			break;
		default:
			std::cerr << "Invalid direction." << std::endl;
			ret = {0, 0, 0};
			break;
	}
	return normalize(ret);
}

float Direction::linePlaneIntersection(vec planePoint, vec linePoint, vec planeNormal, vec lineVec)
{
	float denominator{scalarProduct(lineVec, planeNormal)};
	if(denominator == 0)
	{
		return 0;
	}
	return scalarProduct(vecMinus(planePoint, linePoint), planeNormal) / denominator;
}

bool Direction::pointInTriangle(stl_reader::StlMesh<float, unsigned int> *mesh, const size_t ti, vec point)
{
	// Convert point to barycentric coordinates
	float b0{vecLength(vecMinus(stlToVec(mesh->tri_corner_coords(ti, 0)), stlToVec(mesh->tri_corner_coords(ti, 1)))) * point[0]};
	float b1{vecLength(vecMinus(stlToVec(mesh->tri_corner_coords(ti, 0)), stlToVec(mesh->tri_corner_coords(ti, 2)))) * point[1]};
	float b2{vecLength(vecMinus(stlToVec(mesh->tri_corner_coords(ti, 1)), stlToVec(mesh->tri_corner_coords(ti, 2)))) * point[2]};
	return 0 <= b0 and 0 <= b1 and 0 <= b2 and b0 <= 1 and b1 <= 1 and b2 <= 1;
}

void Direction::intersect(stl_reader::StlMesh<float, unsigned int> *mesh, const size_t ti)
{
	float newLength{linePlaneIntersection(stlToVec(mesh->tri_corner_coords(ti, 0)), tile->getCenter(), stlToVec(mesh->tri_normal(ti)), getVec())};
	// Check if the intersection is actually in the triangle - previously we intersected with the whole plane, not just the triangle
	if(pointInTriangle(mesh, ti, vecPlus(tile->getCenter(), vecTimes(newLength, getVec()))) and newLength > 0.0001 and newLength < length)
	{
		length = newLength;
	}
}

void Direction::intersectAll(stl_reader::StlMesh<float, unsigned int> *mesh)
{
	for(size_t i{1}; i < mesh->num_tris(); ++i)
	{
		intersect(mesh, i);
	}
}

void Direction::write(std::vector<std::pair<vec, vec>>& output) const
{
	vec center{tile->getCenter()};
	output.emplace_back(center, vecPlus(center, vecTimes(length, getVec())));
}

Direction::Direction(const Tile *tile, const int direction) : tile{tile}, direction{direction}, length{0}
{
	setLength();
}

void Direction::setLength()
{
	switch(direction)
	{
		case 0:
		case 2:
		case 6:
		case 8:
		case 17:
		case 19:
		case 23:
		case 25:
			length = 1.7320508075688772/2; // sqrt(3)
			break;
		case 1:
		case 3:
		case 5:
		case 7:
		case 9:
		case 11:
		case 14:
		case 16:
		case 18:
		case 20:
		case 22:
		case 24:
			length = 1.4142135623730951/2; // sqrt(2)
			break;
		case 4:
		case 10:
		case 12:
		case 13:
		case 15:
		case 21:
			length = 1.0/2;
			break;
		default:
			length = 0;
	}
	length *= tile->getColumn()->getLayer()->getLattice()->getTileSize();
}
