#include<cstdio>
#include <iostream>
#include"Zombie.h"

int Zombie::TotalNum = 0;

std::ostream & operator << (std::ostream & os, const Zombie &z)
{
    os << "Damage: " << z.Attack() << " HP:";
    for(int i = 0;i < z.Hp() ;++i)
    {
        os << "*";
    }
    os << std::endl;
    return os;
}

