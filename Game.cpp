#include "Game.h"
#include <cstdlib>
#include <ctime>

Game::Game(int lands, int zombies):numOfLand_(lands),numOfZombie_(zombies),
                                   player_(new Player),zombie_(new Zombie[numOfZombie_]),map_(new Map(numOfLand_))
{
    Map *m;
    if(numOfLand_ < LAND_MIN)
    {
        numOfLand_=LAND_MIN;
        m=new Map(numOfLand_);
        delete map_;
        map_=m;
    }
    else if (numOfLand_ > LAND_MAX)
    {
        numOfLand_=LAND_MAX;
        m=new Map(numOfLand_);
        delete map_;
        map_=m;
    }

    Zombie *z;
    if(numOfZombie_ < ZOMBIE_MIN)
    {
        numOfZombie_=ZOMBIE_MIN;
        z=new Zombie[numOfZombie_];
        delete [] zombie_;
        zombie_=z;
    }
    else if (numOfZombie_ > ZOMBIE_MAX)
    {
        numOfZombie_=ZOMBIE_MAX;
        z=new Zombie[numOfZombie_];
        delete [] zombie_;
        zombie_=z;
    }
}

Game::~Game()
{
    delete player_;
    delete [] zombie_;
    delete map_;
    while(!plant_.empty())
    {
        delete plant_.back();
        plant_.pop_back();
    }
}
