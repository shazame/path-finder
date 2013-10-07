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
	init_pair( 2, COLOR_BLUE,  COLOR_BLUE  );
	//init_pair( 2, COLOR_BLACK, COLOR_BLACK );
	init_pair( 3, COLOR_BLACK, COLOR_RED   );
	init_pair( 4, COLOR_BLACK, COLOR_GREEN );

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
DisplayNcurses::printMapTile(Map &m, unsigned int row, unsigned int col) const {
	if ( m.hasObstacle( row,  col )) {
		printTile( row, col, 2, " " );
	}
	else if ( m.isExit( row,  col )) {
		printTile( row, col, 3, "S" );
	}
	else if ( m.isEntry( row,  col )) {
		printTile( row, col, 4, "E" );
	}
}

void
DisplayNcurses::printTile( unsigned int row, unsigned int col,
		int color_no, const char* car ) const {

	wattron( map_win_, COLOR_PAIR( color_no ));
	for ( int r = 0; r < tile_height_; r++ ) {
		for ( int c = 0; c < tile_width_; c++ ) {
			if ( r == tile_height_ / 2 && c == tile_width_ / 2 ) {
				mvwprintw( map_win_,
						row * tile_height_ + r,
						col * tile_width_  + c, car );
			}
			else {
				mvwprintw( map_win_,
						row * tile_height_ + r,
						col * tile_width_  + c, " " );
			}
		}
	}
	wattroff( map_win_, COLOR_PAIR( color_no ));
}

void
DisplayNcurses::printTileRed(unsigned int row, unsigned int col) const {
	printTile( row, col, 3, " " );
}

} // end namespace path_finder
