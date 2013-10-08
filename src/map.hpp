#ifndef MAP_H
#define MAP_H

#include "tile.hpp"

#include <vector>

#include <stdexcept>

namespace path_finder {

class Map
{
public:
	Map();
	Map(unsigned int height, unsigned int width);
	virtual ~Map();

	// Init the map with a random state
	virtual void randomize(void);

	virtual void resize(unsigned int h, unsigned int w);
	unsigned int getHeight(void) const;
	unsigned int getWidth(void)  const;

	void setObstacle(bool is_obstacle ,unsigned int row, unsigned int col) 
		throw ( std::range_error );
	bool hasObstacle(unsigned int row, unsigned int col) const;

	void setCost(int cost, unsigned int row, unsigned int col);
	int  getCost(unsigned int row, unsigned int col) const;

	bool isEntry( unsigned int row, unsigned int col ) const;
	bool isExit(  unsigned int row, unsigned int col ) const;

protected:
	struct Cell {
		unsigned int r_, c_;
	};

	Cell exit_cell_;
	Cell entry_cell_;

	unsigned int height_, width_;
	std::vector<std::vector<Tile> > tiles_;

	bool isValidPos(unsigned int row, unsigned int col) const;
};

} // namespace path_finder

#endif // MAP_H
