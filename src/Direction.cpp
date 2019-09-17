#include "main.hpp"

const bool Direction::operator!=(const Direction& other) const
{
	return this->tile != other.tile || this->direction != other.direction;
}

Direction* Direction::operator++()
{
	++this->direction;
	return this;
}

Direction& Direction::operator*()
{
	return *this;
}

const vec Direction::getVec() const
{
	switch(this->direction)
	{
		case 0:
			return {-1, -1, -1};
		case 1:
			return {-1, -1, 0};
		case 2:
			return {-1, -1, 1};
		case 3:
			return {-1, 0, -1};
		case 4:
			return {-1, 0, 0};
		case 5:
			return {-1, 0, 1};
		case 6:
			return {-1, 1, -1};
		case 7:
			return {-1, 1, 0};
		case 8:
			return {-1, 1, 1};
		case 9:
			return {0, -1, -1};
		case 10:
			return {0, -1, 0};
		case 11:
			return {0, -1, 1};
		case 12:
			return {0, 0, -1};
		case 13:
			return {0, 0, 1};
		case 14:
			return {0, 1, -1};
		case 15:
			return {0, 1, 0};
		case 16:
			return {0, 1, 1};
		case 17:
			return {1, -1, -1};
		case 18:
			return {1, -1, 0};
		case 19:
			return {1, -1, 1};
		case 20:
			return {1, 0, -1};
		case 21:
			return {1, 0, 0};
		case 22:
			return {1, 0, 1};
		case 23:
			return {1, 1, -1};
		case 24:
			return {1, 1, 0};
		case 25:
			return {1, 1, 1};
		default:
			std::cerr << "Invalid direction." << std::endl;
			return {0, 0, 0};
	}
}

vec Direction::stlToVec(const float *stlVec)
{
	return {*stlVec, *(stlVec + 1), *(stlVec + 2)};
}

vec Direction::vecMinus(vec a, vec b)
{
	return {a[0] - b[0], a[1] - b[1], a[2] - b[2]};
}

float Direction::scalarProduct(vec a, vec b)
{
	return a[0] * b[0] + a[1] * b[1] + a[2] * b[2];
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

void Direction::intersect(stl_reader::StlMesh<float, unsigned int> *mesh, const size_t ti)
{
	float newLength{linePlaneIntersection(stlToVec(mesh->tri_corner_coords(ti, 0)), tile->getCenter(), stlToVec(mesh->tri_normal(ti)), getVec())};
	if(newLength > 0 and newLength < length)
	{
		length = newLength;
	}
}

Direction::Direction(const Tile *tile, const int direction) : tile{tile}, direction{direction}
{
	switch(this->direction)
	{
		case 0:
		case 2:
		case 6:
		case 8:
		case 17:
		case 19:
		case 23:
		case 25:
			length = 1.7320508075688772; // sqrt(3)
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
			length = 1.4142135623730951; // sqrt(2)
			break;
		case 4:
		case 10:
		case 12:
		case 13:
		case 15:
		case 21:
			length = 1;
			break;
		default:
			std::cerr << "Invalid direction." << std::endl;
			length = 0;
	}
}
