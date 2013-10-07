#ifndef DISPLAY_NCURSES_H
#define DISPLAY_NCURSES_H

#include <ncurses.h>
#include "map.hpp"
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
	void printTileRed(unsigned int row, unsigned int col) const ;

protected:
	WINDOW* map_win_;
	int tile_height_, tile_width_;

	void printMapTile( Map &, unsigned int row, unsigned int col ) const;
	void printTile( unsigned int row, unsigned int col,
			int color_no, const char* car ) const;
};

} // end namespace path_finder

#endif //  DISPLAY_NCURSES_H
