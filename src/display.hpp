#ifndef DISPLAY_H
#define DISPLAY_H

#include "map.hpp"

namespace path_finder {

class Display
{
public:
	// All the resources used by the graphical library used are freed here
	virtual ~Display() {}
	// All the initialisation needed for the graphical library are done here
	virtual void init(Map &) = 0;
	// A generic function to display a map
	virtual void printMap(Map &m) const {
		for ( unsigned int r = 0; r < m.getHeight(); r++ ) {
			for ( unsigned int c = 0; c < m.getWidth(); c++ ) {
				printMapTile(m, r, c);
			}
		}
	}

protected:
	// Specific graphical library function call are done here
	virtual void printMapTile(Map &, unsigned int row, unsigned int col) const = 0;
};

} // end namespace path_finder

#endif // DISPLAY_H
