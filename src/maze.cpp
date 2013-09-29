#include "display.hpp"
#include "display_ncurses.hpp"
#include "maze.hpp"
#include "tile.hpp"

#include <cstdlib>
#include <cstdio>

namespace path_finder {

Maze::Maze(): Map() {
	randomize();
}

/* The parameters give the number of cells of the maze.
 * Cells are surrounded by walls, thus we need tiles for the walls and the
 * cells.
 */
Maze::Maze(unsigned int height, unsigned int width):
	Map( 2 * height + 1, 2 * width + 1 ) {
	randomize();
}

Maze::~Maze() {
}

/* The maze is generated using the Randomized Prim's algorithm
 * (cf. en.wikipedia.org/wiki/Maze_generation_algorithm)
 */
void
Maze::randomize(void) {

#ifdef DEBUG_DISPLAY
	DisplayNcurses display( 1, 1 );

	display.init( *this );
#endif // DEBUG_DISPLAY

	// Place the walls
	for ( unsigned int r = 0; r < height_; r++ ) {
		for ( unsigned int c = 0; c < width_; c++ ) {
			if ( c % 2 == 0 || r % 2 == 0 ) {
				setObstacle( true, r, c );
			}
			else {
				setCost( 0, r, c );
			}
		}
	}

	std::vector<Cell*> candidate_cell_list;

	// Choose a cell near the bounds and mark it as part of the maze
	exit_cell_ = randomBorderCell();
	addCellToMaze( exit_cell_ );

	// Add the cell neighbours to the maze cell candidate list
	addCellNeighbours( exit_cell_, candidate_cell_list );

	// While there are cells in the candidate list
	while ( !candidate_cell_list.empty() ) {
		// Pick a random cell from the list
		Cell* c = pickRandomCell( candidate_cell_list );
#ifdef DEBUG_DISPLAY
		display.printMap( *this );
		display.printTileRed( c->r_, c->c_ );
		getchar();
#endif // DEBUG_DISPLAY


		// Link it with one of it's neighboring cells from the maze
		linkCellToMaze( *c );

		// Add the neighboring cells to the candidate list.
		addCellNeighbours( *c, candidate_cell_list );

		delete c;
	}
}

Maze::Cell&
Maze::randomBorderCell(void) {
	int wall = std::rand() % 4;

	switch ( wall ) {
		case 0:
			// Cell on North wall
			exit_cell_.r_ = 1;
			exit_cell_.c_ = (std::rand() % (( width_ - 1 ) / 2 )) * 2 + 1;
			setObstacle( false, 0, exit_cell_.c_ );
			break;
		case 1:
			// Cell on East wall
			exit_cell_.c_ = width_ - 2;
			exit_cell_.r_ = (std::rand() % (( height_ - 1 ) / 2 )) * 2 + 1;
			setObstacle( false, exit_cell_.r_, exit_cell_.c_ + 1 );
			break;
		case 2:
			// Cell on South wall
			exit_cell_.r_ = height_ - 2;
			exit_cell_.c_ = (std::rand() % (( width_ - 1 ) / 2 )) * 2 + 1;
			setObstacle( false, exit_cell_.r_ + 1, exit_cell_.c_ );
			break;
		default:
			// Cell on West wall
			exit_cell_.c_ = 1;
			exit_cell_.r_ = (std::rand() % (( height_ - 1 ) / 2 )) * 2 + 1;
			setObstacle( false, exit_cell_.r_, 0 );
			break;
	}

	return exit_cell_;
}

void
Maze::addCellNeighbours( Cell& cell, std::vector<Cell*>& list ) {
	addCellToList( cell.r_ - 2, cell.c_, list );
	addCellToList( cell.r_ + 2, cell.c_, list );
	addCellToList( cell.r_, cell.c_ - 2, list );
	addCellToList( cell.r_, cell.c_ + 2, list );
}

void
Maze::addCellToList( int row, int col, std::vector<Cell*>& list ) {
	if ( isValidPos( row, col )
			&& !isCellInMaze( row, col )
			&& 43 != Map::getCost( row, col )) {
		Map::setCost( 43, row, col );
		Cell* c = new Cell;
		c->r_ = row;
		c->c_ = col;
		list.push_back( c );
	}
}

Maze::Cell*
Maze::pickRandomCell( std::vector<Cell*>& list ) const {
	int index = std::rand() % list.size();
	Cell * c = list[ index ];
	list.erase( list.begin() + index );
	return c;
}

void
Maze::addCellToMaze( Cell& cell ) {
	Map::setCost( 42, cell.r_, cell.c_ );
}

bool
Maze::isCellInMaze( int row, int col ) const {
	return 42 == Map::getCost( row, col );
}

void
Maze::linkCellToMaze( Cell& cell ) {
	Cell* c = NULL;
	while ( c == NULL ) {
		int i = std::rand() % 4;
		switch( i ) {
			case 0:
				if ( isCellInMaze( cell.r_, cell.c_ - 2 )) {
					c = new Cell();
					c->r_ =  cell.r_; c->c_ = cell.c_ - 1;
				}
				break;
			case 1:
				if ( isCellInMaze( cell.r_ - 2, cell.c_ )) {
					c = new Cell();
					c->r_ = cell.r_ - 1; c->c_ = cell.c_;
				}
				break;
			case 2:
				if ( isCellInMaze( cell.r_, cell.c_ + 2 )) {
					c = new Cell();
					c->r_ = cell.r_; c->c_ = cell.c_ + 1;
				}
				break;
			default:
				if ( isCellInMaze( cell.r_ + 2, cell.c_ )) {
					c = new Cell();
					c->r_ = cell.r_ + 1; c->c_ = cell.c_;
				}
				break;
		}
	}

	setObstacle( false, c->r_, c->c_ );
	delete c;

	addCellToMaze( cell );
}

/*
void
Maze::linkCellToMaze( Cell& cell ) {
	Cell *c = NULL;
	if ( isCellInMaze( cell.r_, cell.c_ - 2 )) {
		c = new Cell();
		c->r_ =  cell.r_; c->c_ = cell.c_ - 1;
	}
	else if ( isCellInMaze( cell.r_ - 2, cell.c_ )) {
		if (c == NULL) {
			c = new Cell();
			c->r_ = cell.r_ - 1; c->c_ = cell.c_;
		}
		else if ( std::rand() % 4 < 3) {
			c->r_ = cell.r_ - 1; c->c_ = cell.c_;
		}
	}
	else if ( isCellInMaze( cell.r_, cell.c_ + 2 )) {
		if (c == NULL) {
			c = new Cell();
			c->r_ = cell.r_; c->c_ = cell.c_ + 1;
		}
		else if ( std::rand() % 4 < 2) {
			c->r_ = cell.r_; c->c_ = cell.c_ + 1;
		}
	}
	else if ( isCellInMaze( cell.r_ + 2, cell.c_ )) {
		if (c == NULL) {
			c = new Cell();
			c->r_ = cell.r_ + 1; c->c_ = cell.c_;
		}
		else if ( std::rand() % 4 < 1) {
			c->r_ = cell.r_ + 1; c->c_ = cell.c_;
		}
	}
	else {
		printf("ERROR: no connection to maze\n");
		return;
	}

	setObstacle( false, c->r_, c->c_ );
	delete c;

	addCellToMaze( cell );
}
*/

} // end namespace path_finder
