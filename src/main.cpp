#include "display.hpp"
#include "display_ncurses.hpp"
#include "maze.hpp"

#include <cstdio>

#define SCREEN_HEIGHT 22
#define SCREEN_WIDTH  88

#define TILE_HEIGHT 1
#define TILE_WIDTH  1

using namespace path_finder;

int main(void) {
	Maze m( SCREEN_HEIGHT / TILE_HEIGHT, SCREEN_WIDTH / TILE_WIDTH );
#ifndef DEBUG_DISPLAY
	DisplayNcurses display( TILE_HEIGHT, TILE_WIDTH );
	display.init( m );
#endif //DEBUG_DISPLAY

#ifndef DEBUG_DISPLAY
	while ( getchar() != 'q' ) {
		display.printMap( m );
#else
	while ( 1 ) {
#endif //DEBUG_DISPLAY
		m.randomize();
	}

	return 0;
}

