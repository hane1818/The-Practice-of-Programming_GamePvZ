#ifndef LAND__
#define LAND__

#include<cstdio>
#include<iostream>

class Plant
{
private:
    char name[10] = {0};
    int price=0;
    int hp=50;
public:
    Plant()=default;
};

class CoinPlant: public Plant
{

};

class Land
{
private:
    Plant plant_;
public:
    Land():plant_(){};
    ~Land(){};

    void Planting(const Plant & x)
    {
        plant_ = x;
    }
};

#endif // ZOMBIE
