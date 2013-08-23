#include "map.hpp"

#include <cstdlib>

namespace path_finder {

Map::Map(): height_(0), width_(0), tiles_() {
}

Map::Map(unsigned int height, unsigned int width):
	height_( height ), width_( width ),
	tiles_( height_, std::vector<Tile>( width_ ) ) {
}

Map::~Map() {
}

void
Map::randomize(void) {
	for ( unsigned int r = 0; r < height_; r++ ) {
		for ( unsigned int c = 0; c < width_; c++ ) {
			if ( rand() % 2 ) {
				setObstacle(r, c);
			}
		}
	}
}

void
Map::resize(unsigned int h, unsigned int w) {
	height_ = h; width_ = w;

	tiles_.resize(h);

	for ( unsigned int i = 0; i < h; i++ ) {
		tiles_[i].resize(w);
	}
}

unsigned int
Map::getHeight(void) const {
	return height_;
}

unsigned int
Map::getWidth(void) const {
	return width_;
}

// TODO
// Add exception if position over size
void
Map::setObstacle(unsigned int row, unsigned int col) {
	if ( !isValidPos(row, col) ) {
		return;
	}
	else {
		return tiles_[row][col].setTileType( Tile::TT_OBSTACLE );	
	}
}

// TODO
// Add exception if position over size
// For the moment everything out of the grid is an obstacle
bool
Map::hasObstacle(unsigned int row, unsigned int col) const {
	if ( !isValidPos(row, col) ) {
		return Tile::TT_OBSTACLE;
	}
	else {
		return tiles_[row][col].isObstacle();
	}
}

bool
Map::isValidPos(unsigned int row, unsigned int col) const {
	return ( row < height_ && col < width_ );
}

} // end namespace path_finder