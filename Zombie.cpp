#include"Zombie.h"

int Zombie::TotalNum = 0;

void Zombie::Move(const int index)
{
    if( (index - pos_) > MaxMove)
    {
        pos_ = pos_ + MaxMove;
    }
    else if( (pos_ - index) > MaxMove)
    {
        pos_ = pos_ - MaxMove;
    }
    else
    {
        pos_ = index;
    }
}

Zombie & Zombie::operator = (const Zombie & rhs)
{
    pos_ = rhs.pos_;
    hp_ = rhs.hp_;
    attack_ = rhs.attack_;
    return (*this);
}

std::ostream & operator << (std::ostream & os, const Zombie &z)
{
    os << "Damage: " << z.Attack() << " HP:";
    for(int i = 0; i < z.Hp() ; ++i)
    {
        os << "*";
    }
    os << std::endl;
    return os;
}

