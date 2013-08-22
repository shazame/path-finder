#include "gtest/gtest.h"

#include "tile.hpp"

using path_finder::Tile;

TEST (Tile, TileCoherence) {
	Tile foo;

	ASSERT_FALSE( foo.isObstacle() );

	foo.setTileType( Tile::TT_OBSTACLE );

	ASSERT_TRUE( foo.isObstacle() );
}

