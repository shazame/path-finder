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
	virtual void randomize( void );
	void randomizeInit( void );
	bool randomizeContinue( void );
	void randomizeStep( void );
	void randomizeEnd( void );

	virtual void resize(unsigned int h, unsigned int w);

private:
	std::vector<Cell*> candidate_cell_list;

	bool  isBorderCell( Cell& cell );
	void  setOnBorder( Cell& cell );
	Cell& randomBorderCell( void );

	void  addCellNeighboursToCandidateList( Cell& cell ) ;
	void  addCellToCandidateList( int row, int col );
	Cell* pickRandomCell( std::vector<Cell*>& list ) const;

	void addCellToMaze( Cell& cell );
	bool isCellInMaze( int row, int col ) const;
	void linkCellToMaze( Cell& cell );
};

}

#endif // MAZE_H
