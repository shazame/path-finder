#include "gtest/gtest.h"

#include "maze.hpp"

using path_finder::Maze;

TEST (Maze, MazeInit) {
	Maze bar;

	ASSERT_EQ( 0, bar.getWidth()  );
	ASSERT_EQ( 0, bar.getHeight() );

}

TEST (Maze, MazeCoherence) {
	Maze bar( 4, 7 );

	ASSERT_FALSE( bar.hasObstacle(2, 5) );

	bar.setObstacle( 2, 5 );

	ASSERT_TRUE( bar.hasObstacle(2, 5) );
}

TEST (Maze, MazeResize) {
	Maze baz;

	baz.resize(5, 10);

	for ( int r = 0; r < 5; r++ ) {
	   for ( int c = 0; c < 10; c++) {	
		   ASSERT_FALSE( baz.hasObstacle(r, c) );
	   }
	}

	baz.setObstacle( 3, 1 );

	ASSERT_TRUE( baz.hasObstacle(3, 1) );
}
