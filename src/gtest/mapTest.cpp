#include "gtest/gtest.h"

#include "map.hpp"

using path_finder::Map;

TEST (Map, MapInit) {
	Map bar;

	ASSERT_EQ( 0, (int) bar.getWidth()  );
	ASSERT_EQ( 0, (int) bar.getHeight() );
}

TEST (Map, MapCoherence) {
	Map bar( 4, 7 );

	ASSERT_FALSE( bar.hasObstacle(2, 5) );

	try {
		bar.setObstacle( true, 2, 5 );
	}
	catch ( std::range_error& e ) {
		std::cerr << "range error caught: " << e.what() << std::endl;
	}

	ASSERT_TRUE( bar.hasObstacle(2, 5) );
}

TEST (Map, MapResize) {
	Map baz;

	baz.resize(5, 10);

	for ( int r = 0; r < 5; r++ ) {
	   for ( int c = 0; c < 10; c++) {	
		   ASSERT_FALSE( baz.hasObstacle(r, c) );
	   }
	}

	try {
		baz.setObstacle( true, 3, 1 );
	}
	catch ( std::range_error& e ) {
		std::cerr << "range error caught: " << e.what() << std::endl;
	}

	ASSERT_TRUE( baz.hasObstacle(3, 1) );
}
