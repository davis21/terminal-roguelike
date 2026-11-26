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

// TEST FUNCTION
Map Map::fromLayout(const std::vector<std::string>& rows)
{
    // Check if map is empty
    if (rows.empty())
    {
        throw std::invalid_argument("This map is empty. Please enter a real map.");
    }

    // Set up function variables
    int height = static_cast<int>(rows.size());
    int width = static_cast<int>(rows[0].size());
    
    // Check if any row is a different length from the first
    for (int i = 0; i < height; ++i)
    {
        if (static_cast<int>(rows[i].size()) != width)
        {
            throw std::invalid_argument("The map has an incorrect length in row: " + std::to_string(i));
        }
    }

    // Check each character to see if they are either a '.' or a '#'    
    for (int y = 0; y < height; ++y)
    {
        for (int x = 0; x < width; ++x)
        {
            char tile = rows[y][x];

            if (tile != '#' && tile != '.')
            {
                throw std::invalid_argument("The map contains a bad character '" + std::string(1, tile) + "' at position " + std::to_string(x) + ", " + std::to_string(y) + ".");
            }                
        }
    }

    // Create a map object using the height and width
    Map mapFromLayout(width, height);

    // Loop over every tile in the map and call setFloor whenever there is a '.'
    for (int y = 0; y < height; ++y)
    {
        for (int x = 0; x < width; ++x)
        {
            char tile = rows[y][x];

            if (tile == '.')
            {
                mapFromLayout.setFloor({x, y});                            
            }
        }
    }

    return mapFromLayout;
}