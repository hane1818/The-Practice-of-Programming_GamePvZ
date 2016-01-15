#ifndef GAME__
#define GAME__
#include <iostream>
#include <vector>
#include "Player.h"
#include "Zombie.h"
#include "Map.h"

class Game
{
    friend std::ostream & operator << (std::ostream & os, const Game & game);

public:
    Game(int lands, int zombies);
    ~Game();
    void doZombie(int z_ind) const;
    void movePlayer(int pos) const;
    void moveZombie(Zombie & z, int pos) const;
    bool endGame() const;
    bool aliveZombie(int z_ind) const { return zombie_[z_ind].isAlive(); }
    static constexpr int LAND_DEFAULT=8;
    static constexpr int LAND_MAX=10;
    static constexpr int LAND_MIN=1;
    static constexpr int ZOMBIE_DEFAULT=3;
    static constexpr int ZOMBIE_MAX=10;
    static constexpr int ZOMBIE_MIN=1;
private:
    void initPlant();
    Player *player_=nullptr;
    Zombie *zombie_=nullptr;
    Map *map_=nullptr;
    std::vector<Plant*> plant_;
    int numOfZombie_=ZOMBIE_DEFAULT;
    int numOfLand_=LAND_DEFAULT;
    int limitStep(int pos) const;
    bool allZombiesDie() const;
};

std::ostream & operator << (std::ostream & os, const Game & game);
#endif // GAME__
