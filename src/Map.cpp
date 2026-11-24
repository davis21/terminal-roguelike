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

bool Map::inBounds(int x, int y) const
{
    return (x >= 0 && x < width && y >= 0 && y < height);
}

bool Map::isWalkable(int x, int y) const
{
    return getTile(x, y) == Tile::Floor;
}

void Map::setFloor(int x, int y)
{
    if (inBounds(x, y))
    {
        tiles[y][x] = Tile::Floor;
    }
}

Tile Map::getTile(int x, int y) const
{
    if (inBounds(x, y))
    {
        return tiles[y][x];
    }
    return Tile::Wall; // Return Wall if out of bounds
}