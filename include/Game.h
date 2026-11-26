#pragma once

#include "Map.h"
#include "Player.h"
#include "Position.h"
#include "Monster.h"

#include <vector>

class Game
{
private:
    Map map;
    Player player;
    std::vector<Monster> monsters;

    bool isBlocked(Position pos) const;

public:
    Game(const Map& startMap, Position playerStart);

    bool tryToMovePlayer(Direction dir);

    const Map& getMap() const;
    const Player& getPlayer() const;

    void addMonster(const Monster& monster);
    const std::vector<Monster>& getMonsters() const;
    const Monster* monsterAt(Position pos) const;
};