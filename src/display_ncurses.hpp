#ifndef DISPLAY_NCURSES_H
#define DISPLAY_NCURSES_H

#include <ncurses.h>
#include "display.hpp"

namespace path_finder {

class DisplayNcurses: public Display
{
	public:
	DisplayNcurses();
	DisplayNcurses( int tile_height, int tile_width );
	~DisplayNcurses();
	void init( Map & );
	void printMap( Map & )const;

	private:
	WINDOW* map_win_;
	int tile_height_, tile_width_;

	void printTile( Map &, unsigned int row, unsigned int col ) const;
};

} // end namespace path_finder

#endif //  DISPLAY_NCURSES_H
