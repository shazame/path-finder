#include "tile.hpp"

namespace path_finder {

Tile::Tile(): cost_(0), type_(TT_NORMAL) {
}

Tile::~Tile() {
}

void
Tile::setTileType(TileType tt) {
	type_ = tt;
}

bool
Tile::isObstacle() const {

	return type_ == TT_OBSTACLE;
}

void
Tile::setCost( int cost ) {
	cost_ = cost;
}

int
Tile::getCost() const {
	return cost_;
}

} // end namespace path_finder
