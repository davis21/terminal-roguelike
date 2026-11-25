#include "Map.h"
#include <stdexcept>

// This is where we will implement the functions defined in the Map class. The Map class is responsible for managing the game map, which is a 2D grid of tiles.
// Each tile can either be a wall or a floor, and the class provides methods to manipulate and query the map.

Map::Map(int w, int h) : width(w), height(h)
{
    if (w <= 0 || h <= 0) {
        throw std::invalid_argument("Map dimensions must be positive");
    }
    tiles.assign(h, std::vector<Tile>(w, Tile::Wall));
}

int Map::getWidth() const { return width; }
int Map::getHeight() const { return height; }

bool Map::inBounds(Position pos) const
{
    return (pos.x >= 0 && pos.x < width && pos.y >= 0 && pos.y < height);
}

bool Map::isWalkable(Position pos) const
{
    return getTile(pos) == Tile::Floor;
}

void Map::setFloor(Position pos)
{
    if (inBounds(pos))
    {
        tiles[pos.y][pos.x] = Tile::Floor;
    }
}

Tile Map::getTile(Position pos) const
{
    if (inBounds(pos))
    {
        return tiles[pos.y][pos.x];
    }
    return Tile::Wall; // Return Wall if out of bounds
}