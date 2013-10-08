#include "gtest/gtest.h"

#include "maze.hpp"

using path_finder::Maze;

TEST (Maze, MazeInit) {
	Maze bar;

	ASSERT_EQ( 5, (int) bar.getWidth()  );
	ASSERT_EQ( 5, (int) bar.getHeight() );
}

TEST (Maze, MazeCoherence) {
	Maze bar( 4, 7 );

	ASSERT_FALSE(
			bar.hasObstacle( 1, 4 ) &&
			bar.hasObstacle( 1, 5 ) &&
			bar.hasObstacle( 1, 6 ) &&
			bar.hasObstacle( 2, 4 ) &&
			bar.hasObstacle( 2, 5 ) &&
			bar.hasObstacle( 2, 6 ) &&
			bar.hasObstacle( 3, 4 ) &&
			bar.hasObstacle( 3, 5 ) &&
			bar.hasObstacle( 3, 6 ) );

	ASSERT_FALSE(
			!bar.hasObstacle( 1, 4 ) &&
			!bar.hasObstacle( 1, 5 ) &&
			!bar.hasObstacle( 1, 6 ) &&
			!bar.hasObstacle( 2, 4 ) &&
			!bar.hasObstacle( 2, 5 ) &&
			!bar.hasObstacle( 2, 6 ) &&
			!bar.hasObstacle( 3, 4 ) &&
			!bar.hasObstacle( 3, 5 ) &&
			!bar.hasObstacle( 3, 6 ) );
}

TEST (Maze, MazeResize) {
	Maze baz;

	baz.resize(5, 10);

	for ( int r = 1; r < 4; r++ ) {
		for ( int c = 1; c < 9; c++) {
			ASSERT_FALSE(
					baz.hasObstacle( r - 1, c - 1 ) &&
					baz.hasObstacle( r - 1, c     ) &&
					baz.hasObstacle( r - 1, c + 1 ) &&
					baz.hasObstacle( r    , c - 1 ) &&
					baz.hasObstacle( r    , c     ) &&
					baz.hasObstacle( r    , c + 1 ) &&
					baz.hasObstacle( r + 1, c - 1 ) &&
					baz.hasObstacle( r + 1, c     ) &&
					baz.hasObstacle( r + 1, c + 1 ) );

			ASSERT_FALSE(
					!baz.hasObstacle( r - 1, c - 1 ) &&
					!baz.hasObstacle( r - 1, c     ) &&
					!baz.hasObstacle( r - 1, c + 1 ) &&
					!baz.hasObstacle( r    , c - 1 ) &&
					!baz.hasObstacle( r    , c     ) &&
					!baz.hasObstacle( r    , c + 1 ) &&
					!baz.hasObstacle( r + 1, c - 1 ) &&
					!baz.hasObstacle( r + 1, c     ) &&
					!baz.hasObstacle( r + 1, c + 1 ) );
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
