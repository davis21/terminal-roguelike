#include "Renderer.h"

namespace
{
    char tileToChar(Tile tile)
    {
        switch (tile)
        {
            case Tile::Wall: return '#';
            case Tile::Floor: return '.';
        }
        return '?';
    }
}

void render(const Game& game, std::ostream& out)
{
    const Map& map = game.getMap();
    Position playerPos = game.getPlayer().getPosition();
    
    for (int y = 0; y < map.getHeight(); ++y)
    {
        for (int x = 0; x < map.getWidth(); ++x)
        {
            if (Position{x, y} == playerPos)
                out << "@";
            else
                out << tileToChar(map.getTile({x, y}));
        }
        out << '\n';
    }
}
