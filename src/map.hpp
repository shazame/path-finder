#ifndef MAP_H
#define MAP_H

#include "tile.hpp"

#include <vector>

namespace path_finder {

class Map
{
	public:
		Map();
		Map(unsigned int height, unsigned int width);
		virtual ~Map();

		// Init the map with a random state
		virtual void randomize(void);

		void resize(unsigned int h, unsigned int w);
		unsigned int getHeight(void) const;
		unsigned int getWidth(void)  const;

		void setObstacle(unsigned int row, unsigned int col);
		bool hasObstacle(unsigned int row, unsigned int col) const;

	protected:
		unsigned int height_, width_;
		std::vector<std::vector<Tile> > tiles_;

		bool isValidPos(unsigned int row, unsigned int col) const;
};

}

#endif // MAP_H
