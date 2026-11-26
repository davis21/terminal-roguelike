#pragma once

// Different Libraries and headers that will be used in the project.
#include <string>
#include <vector>
#include "Position.h"


// Enum class to represent the different types of tiles in the game. Each tile can either be a wall or a floor.
enum class Tile { Wall, Floor };

// Setting up a class to handle the map of the game. The map will be a 2D grid of tiles, where each tile can be either a wall or a floor.
class Map {

private:
    int width;  // Width of the map
    int height; // Height of the map
    std::vector<std::vector<Tile>> tiles; // 2D vector to hold the tiles

public:
    // Constructor to initialize the map with a given width and height. It will fill the map with walls by default.
    Map(int w, int h);

    int getWidth() const;  // Function to get the width of the map
    int getHeight() const; // Function to get the height of the map

    // Check if the given coordinates (x, y) are within the bounds of the map. Returns true if they are, false otherwise.
    bool inBounds(Position pos) const;

    // Check if the tile at the given coordinates (x, y) is walkable (i.e., it is a floor tile). Returns true if it is walkable, false otherwise.
    bool isWalkable(Position pos) const;

    // Set the tile at the given coordinates (x, y) to be a floor tile. This function will only set the tile if the coordinates are within bounds.
    void setFloor(Position pos);

    // Get the tile type at the given coordinates (x, y). Returns the Tile enum value for the tile. If the coordinates are out of bounds, it returns Tile::Wall.
    Tile getTile(Position pos) const;

    // TEST FUNCTION
    // Should make a map from a picture
    static Map fromLayout(const std::vector<std::string>& rows);
};