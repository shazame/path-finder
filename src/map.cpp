#include "map.hpp"

#include <cstdlib>
#include <ctime>

namespace path_finder {

Map::Map(): height_(0), width_(0), tiles_() {
}

Map::Map(unsigned int height, unsigned int width):
	height_( height ), width_( width ),
	tiles_( height_, std::vector<Tile>( width_ ) ) {
	// Initialize the random number generator
	std::srand( std::time( 0 ));
}

Map::~Map() {
}

void
Map::randomize(void) {
	for ( unsigned int r = 0; r < height_; r++ ) {
		for ( unsigned int c = 0; c < width_; c++ ) {
			if ( std::rand() % 2 ) {
				setObstacle( true, r, c );
			}
			else {
				setObstacle( false, r, c );
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

void
Map::setObstacle(bool is_obstacle, unsigned int row, unsigned int col)
	throw ( std::range_error ) {

	if ( !isValidPos(row, col) ) {
		throw std::range_error( "ERROR: given cell position is out of range." );
	}
	else if ( is_obstacle ) {
		tiles_[row][col].setTileType( Tile::TT_OBSTACLE );	
	}
	else {
		tiles_[row][col].setTileType( Tile::TT_NORMAL );	
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

void
Map::setCost(int cost, unsigned int row, unsigned int col) {
	if ( !isValidPos(row, col) ) {
		return;
	}

	tiles_[row][col].setCost( cost );
}

int
Map::getCost(unsigned int row, unsigned int col) const {
	if ( !isValidPos(row, col) ) {
		return -1;
	}

	return tiles_[row][col].getCost();
}

bool
Map::isValidPos(unsigned int row, unsigned int col) const {
	return ( row < height_ && col < width_ );
}

bool
Map::isEntry( unsigned int row, unsigned int col ) const {
	return ( entry_cell_.r_ == row && entry_cell_.c_ == col );
}

bool
Map::isExit(  unsigned int row, unsigned int col ) const {
	return ( exit_cell_.r_ == row && exit_cell_.c_ == col );
}


} // end namespace path_finder
