#ifndef LAND__
#define LAND__

#include <cstdio>
#include <cstring>
#include <iostream>
#include "Player.h"
#include "Plant.h"

/*Land: Is it empty. Which plants it has. plant a plant on it*/
class Land
{
private:
    Plant * plant_ = nullptr;
    bool isEmpty_ = true;
public:
    Land(){};
    Land(Plant * x):plant_(x),isEmpty_(false) {};
    Land(Land & x) {};
    Land & operator = (const Land & rhs)
    {
        plant_ = rhs.plant_;
        isEmpty_ = rhs.isEmpty_;
        return (*this);
    }
    ~Land() {};
    Plant * GetPlant()
    {
        return plant_;
    }
    bool IsEmpty() //Is the land empty?
    {
        return (isEmpty_);
    }
    void Planting(Player &p , Plant & x) // Plant sth in the land
    {
        plant_ = &x;
        isEmpty_ = false;
        p.CostMoney(x.Price());
    }

    friend::std::ostream & operator << (std::ostream &os, const Land &l)
    {
        if(l.isEmpty_) os << "Empty";
        else os << (*l.plant_);
        return os;
    }
};


#endif // LAND
