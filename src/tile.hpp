#ifndef TILE_H
#define TILE_H

namespace path_finder {

class Tile
{
	public:
		enum TileType {
			TT_NORMAL,
			TT_OBSTACLE,
		};

		Tile();
		~Tile();

		void setTileType(TileType tt);
		bool isObstacle() const;

		void setCost( int cost );
		int  getCost() const;

	private:
		int      cost_;
		TileType type_;
};

}

#endif // TILE_H
