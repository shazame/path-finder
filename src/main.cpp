#include "display.hpp"
#include "display_ncurses.hpp"
#include "maze.hpp"

#include <cstdio>

// For usleep
#include <unistd.h>

#define SCREEN_HEIGHT 22
#define SCREEN_WIDTH  88

#define TILE_HEIGHT 1
#define TILE_WIDTH  2

//#define DEBUG_DISPLAY

using namespace path_finder;

int main(void) {
	Maze m( SCREEN_HEIGHT / TILE_HEIGHT, SCREEN_WIDTH / TILE_WIDTH );
	DisplayNcurses display( TILE_HEIGHT, TILE_WIDTH );
	display.init( m );

	do {
		m.randomizeInit();

		while( m.randomizeContinue() ) {
			m.randomizeStep();
#ifdef DEBUG_DISPLAY
			display.printMap( m );
			usleep( 1000 );
#endif //DEBUG_DISPLAY
		}

		m.randomizeEnd();

		display.printMap( m );
	} while ( getchar() != 'q' );

	return 0;
}

