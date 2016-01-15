#include "Land.h"

void Land::Planting(Player &p , Plant & x) // Plant sth in the land
{
    plant_ = x.New();
    isEmpty_ = false;
    p.CostMoney(x.Price());
}

bool Land::Dead()
{
    if(plant_->Hp() > 0)
    {
        return false;
    }
    delete plant_;
    isEmpty_ = true;
    return true;
}

Land & Land::operator = (const Land & rhs)
{
    plant_ = rhs.plant_;
    isEmpty_ = rhs.isEmpty_;
    return (*this);
}

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
