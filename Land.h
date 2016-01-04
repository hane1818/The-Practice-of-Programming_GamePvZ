#ifndef LAND__
#define LAND__

#include<cstdio>
#include<cstring>
#include<iostream>

class Plant
{
protected:
    std::string name_ = "\0";
    int price_=0;
    int hp_=50;
public:
    Plant()=default;
    Plant(const std::string name,const int price,const int hp):name_(name),price_(price),hp_(hp)
    {

    };
    virtual void Display()const
    {
        std::cout << name_;
    }
};

class CoinPlant: public Plant
{
public:
    CoinPlant():Plant("CoinPlant",50,50)
    {

    }
};
/*Land: Is it empty. Which plants it has. plant a plant on it*/
class Land
{
private:
    Plant plant_;
    bool isEmpty_;
public:
    Land():plant_(),isEmpty_(true){};
    ~Land(){};
    bool IsEmpty()
    {
        return (isEmpty_);
    }
    void Planting(Plant & x)
    {
        plant_ = x;
        isEmpty_ = false;
    }
    void Print()
    {
        if(IsEmpty())
        {
            std::cout << "Empty";
        }
        else
        {
            plant_.Display();
        }
    }
};

#endif // LAND
