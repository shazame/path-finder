#include "display_ncurses.hpp"

#include <stdlib.h>
#include <stdio.h>

namespace path_finder {

DisplayNcurses::DisplayNcurses(): 
	tile_height_( 1 ), 
	tile_width_ ( 1 ) {
}

DisplayNcurses::DisplayNcurses( int tile_height, int tile_width ): 
	tile_height_( tile_height ),
	tile_width_ ( tile_width  ) {
}

DisplayNcurses::~DisplayNcurses() {
	delwin( map_win_ );
	endwin();
}

// raise and exception instead
void
DisplayNcurses::init(Map &m) {
	initscr();

	if ( has_colors() == FALSE ) {
		endwin();
		printf( "Your terminal does not support color\n" );
		exit( EXIT_FAILURE );
	}
    start_color();

	init_pair( 1, COLOR_WHITE, COLOR_WHITE );
	init_pair( 2, COLOR_BLACK, COLOR_BLACK );

	// prepare the console for writing
	refresh();

	// create a new window in the middle of the screen
	int win_height = m.getHeight() * tile_height_;
	int win_width  = m.getWidth()  * tile_width_ ;
	int scr_row = 0, scr_col = 0;
	getmaxyx( stdscr, scr_row, scr_col );
	int win_row = ( scr_row - win_height ) / 2;
	int win_col = ( scr_col - win_width  ) / 2;
	if ( win_height > scr_row || win_width > scr_col ) {
		endwin();
		printf("Screen too small\n");
		exit( EXIT_FAILURE );
	}
	map_win_ = newwin( win_height, win_width, win_row, win_col );
}

void
DisplayNcurses::printMap(Map &m) const {
	// reset the background of the map to white
	wbkgd( map_win_, COLOR_PAIR( 1 ));

	Display::printMap( m );
	// refresh the window contents
	wrefresh( map_win_ );
}

void
DisplayNcurses::printTile(Map &m, unsigned int row, unsigned int col) const {
	if ( m.hasObstacle( row,  col )) {
		wattron(   map_win_, COLOR_PAIR( 2 ));
		for ( int r = 0; r < tile_height_; r++ ) {
			for ( int c = 0; c < tile_width_; c++ ) {
				mvwprintw( map_win_, 
						row * tile_height_ + r, 
						col * tile_width_  + c, " " );
			}
		}
		wattroff(  map_win_, COLOR_PAIR( 2 ));
	}
}

} // end namespace path_finder
