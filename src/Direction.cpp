#include "main.hpp"

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
	}
	std::cerr << "Invalid direction." << std::endl;
	return {0, 0, 0};
}

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

Direction::Direction(const Tile *tile, const int direction) : tile{tile}, direction{direction}
{}
