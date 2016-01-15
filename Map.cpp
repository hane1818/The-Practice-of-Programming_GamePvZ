#include "Map.h"
#include <iostream>
#include <cstdlib>
#include "Player.h"
#include "Zombie.h"

const int Map::Rand(Player & p) const //Move player and Return index
{
    int index = rand() % size_ ;
    p.Move(index);
    return index;
}

const int Map::Rand(Zombie & z) const //Move a zombie and Return index
{
    int index = rand() % size_ ;
    z.Move(index);
    return index;
}

void Map::Healing(int hpBack) const
{
    for(int i=0; i<size_; ++i)
    {
        if(!GetLand(i)->IsEmpty())
        {
            GetLand(i)->GetPlant()->Damage(-hpBack);
        }
    }
}

bool Map::IsNonPlant() const
{
    for(int i=0; i<size_; i++)
    {
        if(!GetLand(i)->IsEmpty())
            return false;
    }
    return true;
}

void Map::Display(const Player &p , const Zombie * z) const //Display Game Board
{
    for(int i=0; i<size_; i++)
    {
        std::cout << "[" << i << "]{" << ((p.Pos() == i) ? "*" : " ");
        for(int j=0; j<Zombie::TotalNum; j++)
        {
            if(z[j].isAlive())
            {
                if(z[j].Pos() == i) std::cout << j;
                else std::cout << " ";
            }
        }
        std::cout << "}";
        std::cout << map_[i];
        std::cout << std::endl;
    }
}
