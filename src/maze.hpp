#ifndef MAZE_H
#define MAZE_H

#include "map.hpp"

namespace path_finder {

class Maze: public Map
{
	public:
		Maze();

		// Generate a random maze
		Maze(unsigned int height, unsigned int width);
		virtual ~Maze();

		// Generate a new random maze
		virtual void randomize(void);
};

}

#endif // MAZE_H
