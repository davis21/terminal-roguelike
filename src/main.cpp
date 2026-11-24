#include <iostream>
#include <stdexcept>


#include "Map.h"

int main()
{
    Map map(10, 5); // Create a map of width 10 and height 5
    map.setFloor(7, 2); // Set the tile at (7, 2) to be a floor

    // Print the map to the console
    for (int y = 0; y < map.getHeight(); ++y)
    {
        for (int x = 0; x < map.getWidth(); ++x)
        {
            if (map.isWalkable(x, y))
            {
                std::cout << '#'; // Floor tile
            }
            else
            {
                std::cout << '.'; // Wall tile
            }
        }
        std::cout << '\n';
    }

    // Wrap Map bad(-1, 5); in try/catch (const std::invalid_argument& e) and print e.what()
    try
    {
        Map bad(-1, 5); // This should throw an exception
    }
    catch (const std::invalid_argument& e)
    {
        std::cout << "Caught exception: " << e.what() << '\n';
    }
    
    return 0;
}