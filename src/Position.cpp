#include "Position.h"

Position step(Position from, Direction dir)
{
    // Below is the switch that checks what direction as a up, down, left, or right
    switch (dir)
    {
    case Direction::Up:
        from.y--; // Row 0 is the top of the screen, so moving up decreases y.
        break;
    case Direction::Down:
        from.y++;
        break;
    case Direction::Left:
        from.x--;
        break;
    case Direction::Right:
        from.x++;
        break;
    }

    return from;
}