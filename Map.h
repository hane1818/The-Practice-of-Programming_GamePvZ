#ifndef MAP__
#define MAP__

#include <cstdio>
#include <iostream>
#include <cstdlib>
#include "Land.h"
#include "Player.h"
#include "Zombie.h"

class Map
{

private:
    Land * map_;
    size_t size_;
public:
    Map(int size):map_(nullptr),size_(size)
    {
        map_ = new Land[size];
    };
    ~Map()
    {
        delete []map_;
        map_ = nullptr;
        size_ = 0;
    };
    Land * GetLand(const int index)const //Get land index and Return land's address
    {
        return &map_[index];
    }

    const int Rand(Player & p)const //Move player and Return index
    {
        int index = rand() % size_ ;
        p.Move(index);
        return index;
    }

    const int Rand(Zombie & z)const //Move a zombie and Return index
    {
        int index = rand() % size_ ;
        z.Move(index);
        return index;
    }

    void Healing(int hpBack)const
    {
        for(int i=0;i<size_;i++)
        {
            if(!GetLand(i)->IsEmpty())
            {
                GetLand(i)->GetPlant()->Damage(-hpBack);
            }
        }
    }

    bool IsNonPlant()const
    {
        for(int i=0;i<size_;i++)
        {
            if(!GetLand(i)->IsEmpty())
                return false;
        }
        return true;
    }

    void Display(const Player &p , const Zombie * z)const //Display Game Board
    {
        for(int i=0;i<size_;i++)
        {
            std::cout << "[" << i << "]{" << ((p.Pos() == i) ? "*" : " ");
            for(int j=0;j<Zombie::TotalNum;j++)
            {
                if((z[j].Pos() == i && z[j].isAlive())) std::cout << j;
            }
            std::cout << "}";
            std::cout << map_[i];
            std::cout << std::endl;
        }
    }
};

#endif // MAP

