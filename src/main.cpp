#include <iostream>
#include <string>

#include "Game.h"
#include "Input.h"
#include "Renderer.h"
#include "Terminal.h"

const std::vector<std::string> layout = {
    "##############################",
    "#............#...............#",
    "#............#...............#",
    "#....####....#....######.....#",
    "#....#.......................#",
    "#....#.......#.........#.....#",
    "######.......#####.....#.....#",
    "#............#.........#.....#",
    "#....##......#.........###...#",
    "#.....#......................#",
    "#.....#......#...............#",
    "##############################",
};

int main()
{
    Game game(Map::fromLayout(layout), Position{2, 2});
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