#include "maze.hpp"

#include <cstdlib>

namespace path_finder {

Maze::Maze(): Map() {
	randomize();
}

Maze::Maze(unsigned int height, unsigned int width): Map( height, width ) {
	randomize();
}

Maze::~Maze() {
}

// TODO Generate a random maze
void
Maze::randomize(void) {
}

} // end namespace path_finder
