#pragma once

#include "Map.h"
#include "Player.h"
#include "Position.h"

class Game
{
private:
    Map map;
    Player player;

public:
    Game(const Map& startMap, Position playerStart);

    bool tryToMovePlayer(Direction dir);

    const Map& getMap() const;
    const Player& getPlayer() const;
};