#include <iostream>
#include <string>

#include "Game.h"
#include "Input.h"
#include "Renderer.h"
#include "Terminal.h"

namespace
{
    // A 20x10 room with walls around the edge and a small pillar in the middle.
    Map makeStartingMap()
    {
        Map map(20, 10);
        for (int y = 1; y < map.getHeight() - 1; ++y) {
            for (int x = 1; x < map.getWidth() - 1; ++x) {
                map.setFloor({x, y});
            }
        }

        // Turn a few tiles back into walls: just recreate the room
        // without carving them. (No setWall yet, so we skip them instead.)
        return map;
    }
}

int main()
{
    Game game(makeStartingMap(), Position{2, 2});
    std::string message = "Use w/a/s/d to move, q to quit.";

    while (true)
    {
        std::cout << "\x1b[2J\x1b[H";   // clear screen, cursor to top-left
        render(game, std::cout);
        std::cout << message << '\n';
        // std::cout << "> ";

        // char key;
        // if (!(std::cin >> key)) {
        //     break;                      // input closed (e.g. Ctrl+Z / Ctrl+D)
        // }

        char key = readKey();

        std::optional<Command> cmd = parseCommand(key);
        if (!cmd) {
            message = "Unknown key.";
            continue;
        }

        if (*cmd == Command::Quit) {
            break;
        }

        if (std::optional<Direction> dir = toDirection(*cmd)) {
            if (game.tryToMovePlayer(*dir)) {
                message = "";
            } else {
                message = "You bump into a wall.";
            }
        }
    }

    std::cout << "Goodbye!\n";
    return 0;
}