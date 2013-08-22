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
Tile::isObstacle() {
	return type_ == TT_OBSTACLE;
}

} // end namespace path_finder
