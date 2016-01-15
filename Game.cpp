#include "Game.h"
#include <fstream>
#include <string>

using namespace std;

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
    initPlant();
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

bool Game::endGame()
{
    if (map_->IsNonPlant())
    {
        cout << endl << "Oh no... You have no plant on the map ...." << endl;
        return true;
    }
    else if (BombPlant::deadNum > numOfZombie_/2)
    {
        cout << endl << "You lose the game since you cannot use that many bomb plants!" << endl;
        return true;
    }
    else if (allZombiesDie())
    {
        cout << endl << "Congratulations! You have killed all zombies!" << endl;
        return true;
    }
    return false;
}

void Game::initPlant()
{
    fstream fin("plants.txt", fstream::in);
    string str;
    if(fin)
    {
        while(fin >> str)
        {
            Plant *tmp = nullptr;
            switch(str[0])
            {
            case 'C':
            {
                tmp = new CoinPlant(fin);
                break;
            }
            case 'S':
            {
                tmp = new HornPlant(fin);
                break;
            }
            case 'B':
            {
                tmp = new BombPlant(fin);
                break;
            }
            case 'H':
            {
                tmp = new HealPlant(fin);
                break;
            }
            default:
                continue;
            }
            if(tmp)
            {
                plant_.push_back(tmp);
            }
        }
    }
}

bool Game::allZombiesDie()
{
    for(int i=0; i<numOfZombie_ && !zombie_[i].isAlive(); ++i)
        return (i==numOfZombie_-1);
}

std::ostream & operator << (std::ostream & os, const Game & game)
{
    game.map_->Display(*game.player_, game.zombie_);
    cout << "------------------------------------------------" << endl;
    cout << "Zombie information:" << endl;
    for(int i=0; i<game.numOfZombie_; ++i)
    {
        if(game.zombie_[i].isAlive())
            cout << '[' << i << "] " << game.zombie_[i];
    }
    cout << "================================================" << endl;
}
