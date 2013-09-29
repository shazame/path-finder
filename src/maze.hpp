#ifndef MAZE_H
#define MAZE_H

#include "map.hpp"
#include <vector>

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

	private:

		struct Cell {
			unsigned int r_, c_;
		};

		Cell exit_cell_;
		Cell entry_cell_;

		Cell& randomBorderCell(void);

		void addCellNeighbours( Cell& cell, std::vector<Cell*>& list ) ;
		void addCellToList( int row, int col, std::vector<Cell*>& list );
		Cell* pickRandomCell( std::vector<Cell*>& list ) const;

		void addCellToMaze( Cell& cell );
		bool isCellInMaze( int row, int col ) const;
		void linkCellToMaze( Cell& cell );
};

}

#endif // MAZE_H
