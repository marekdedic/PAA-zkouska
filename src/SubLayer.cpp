#include "main.hpp"

SubLayer::SubLayer(Layer *layer, int yMin, int yMax, int zMin, int zMax) : layer{layer}, yMin{yMin}, yMax{yMax}, zMin{zMin}, zMax{zMax}
{

}

Column* SubLayer::begin() const
{
	return layer->columns.at(yMin);
}

Column* SubLayer::end() const
{
	return layer->columns.at(yMax);
}

Column* SubLayer::next(Column *current) const
{
	return layer->next(current);
}

