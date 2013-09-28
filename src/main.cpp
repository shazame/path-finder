#include "display.hpp"
#include "display_ncurses.hpp"
#include "map.hpp"

#include <cstdio>

using namespace path_finder;

int main(void) {
	DisplayNcurses display( 2, 4 );

	Map m( 20, 20 );

	display.init( m );

	while ( getchar() != 'q' ) {
		display.printMap( m );
		m.randomize();
	}

	return 0;
}

