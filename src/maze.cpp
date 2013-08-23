#include "maze.hpp"

#include <cstdlib>

namespace path_finder {

Maze::Maze(): Map() {
}

Maze::Maze(unsigned int height, unsigned int width): Map( height, width ) {
	// Generate a random maze
}

Maze::~Maze() {
}

// TODO Generate a random maze
void
Maze::randomize(void) {
}

} // end namespace path_finder
