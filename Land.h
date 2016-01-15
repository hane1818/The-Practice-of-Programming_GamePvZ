#ifndef LAND__
#define LAND__

#include "Plant.h"
#include <iostream>

class Player;

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
    Land & operator = (const Land & rhs);
    ~Land() {};
    Plant * GetPlant() const { return plant_; }
    bool IsEmpty() const { return (isEmpty_); } //Is the land empty?
    void Planting(Player &p , Plant & x); // Plant sth in the land
    bool Dead();
};

std::ostream & operator << (std::ostream &os, const Land &l);
#endif // LAND
