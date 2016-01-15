#ifndef GAME__
#define GAME__
#include <vector>
#include "Player.h"
#include "Zombie.h"
#include "Map.h"

class Game
{
public:
    static constexpr int LAND_DEFAULT=8;
    static constexpr int LAND_MAX=10;
    static constexpr int LAND_MIN=1;
    static constexpr int ZOMBIE_DEFAULT=3;
    static constexpr int ZOMBIE_MAX=10;
    static constexpr int ZOMBIE_MIN=1;
private:
    Player *player_=nullptr;
    Zombie *zombie_=nullptr;
    Map *map_=nullptr;
    vector<Plant*> plant_;
    int numOfZombie_=ZOMBIE_DEFAULT;
    int numOfLand_=LAND_DEFAULT;
};

#endif // GAME__
