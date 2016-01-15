#ifndef MAP__
#define MAP__

#include "Land.h"

class Player;
class Zombie;

class Map
{
private:
    Land * map_;
    size_t size_;
public:
    Map(int size):map_(nullptr),size_(size) { map_ = new Land[size]; };
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
    const int Rand(Player & p) const; //Move player and Return index
    const int Rand(Zombie & z)const; //Move a zombie and Return index
    void Healing(int hpBack)const;
    bool IsNonPlant() const;
    void Display(const Player &p , const Zombie * z) const; //Display Game Board
};

#endif // MAP

