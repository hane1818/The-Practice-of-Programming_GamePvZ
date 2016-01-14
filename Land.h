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
    Land() {};
    Land(Plant * x):plant_(x),isEmpty_(false) {};
    Land(Land & x) {};
    Land & operator = (const Land & rhs)
    {
        plant_ = rhs.plant_;
        isEmpty_ = rhs.isEmpty_;
        return (*this);
    }
    ~Land() {};
    Plant * GetPlant() const
    {
        return plant_;
    }
    bool IsEmpty() const //Is the land empty?
    {
        return (isEmpty_);
    }
    void Planting(Player &p , Plant & x) // Plant sth in the land
    {
        Plant * tmp = x.New();
        plant_ = tmp;
        isEmpty_ = false;
        p.CostMoney(x.Price());
    }
    bool Dead()
    {
        if(plant_->Hp() > 0)
        {
            return false;
        }
        delete plant_;
        isEmpty_ = true;
        return true;
    }
};

std::ostream & operator << (std::ostream &os, const Land &l)
{
    if(l.IsEmpty())
    {
        os << "Empty";
    }
    else
    {
        os << *(l.GetPlant());
    };
    return os;
}
#endif // LAND
