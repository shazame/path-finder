#include "display.hpp"
#include "display_ncurses.hpp"
#include "maze.hpp"

#include <cstdio>

using namespace path_finder;

int main(void) {
	Maze m( 22, 82 );
#ifndef DEBUG_DISPLAY
	DisplayNcurses display( 1, 1 );
	display.init( m );
#endif //DEBUG_DISPLAY

	while ( getchar() != 'q' ) {
#ifndef DEBUG_DISPLAY
		display.printMap( m );
		m.randomize();
#endif //DEBUG_DISPLAY
	}

	return 0;
}

