#include<string>
#include<fstream>
#include <sstream>
#include<iostream>
#include <vector>
#include <fstream>
/*------*/
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

#ifndef PLANT_H_
#define PLANT_H_
class Plant
{
public:
    Plant()=default;
    Plant(const std::string name,const int price,const int hp):name_(name),price_(price),hp_(hp)
    {

    };
    virtual ~Plant()
    {
        std::cout<<"End"<<std::endl;
    };
    void Attack() {}
    void Damage(int hurt)
    {
        hp_-=hurt;
    }
    bool isAlive()
    {
        return (hp_>0);
    }
    void DerivedPlant(std::fstream & ifs,std::string buffer[]);
private:
    std::string name_;
    const int price_=0;
    int hp_=0;
};
#endif // PLANT_H_
#ifndef CoinPlant_H_
#define CoinPlant_H_
class CoinPlant:public Plant
{
public:
    CoinPlant(std::fstream &ifs)
    {
        std::string buffer[6];
        DerivedPlant(ifs,buffer);
        for(int i=0;i<6;++i)
        {
            std::cout<<buffer[i]<<" <----- "<<std::endl;
        }
        std::string name=buffer[1];
        int price=atoi(buffer[2].substr(1,buffer[2].size()).c_str());
        int hp=atoi(buffer[3].c_str());
        Plant p(name,price,hp);
    };
    ~CoinPlant()
    {
        std::cout<<"Destruct"<<std::endl;
    };
private:
    int round_=2;
    int giveMoney_=100;
};
#endif // CoinPlant_H_
#ifndef HornPlant_H_
#define HornPlant_H_
class HornPlant:public Plant
{
public:

    HornPlant(std::fstream & ifs)
    {
        //DerivedPlant(ifs);
    };
    ~HornPlant() {};
private:


};
#endif // HornPlant_H_
#ifndef BombPlant_H_
#define BombPlant_H_
class BombPlant:public Plant
{
public:

    BombPlant(std::fstream & ifs)
    {
        //DerivedPlant(ifs);
    };
    ~BombPlant() {};
private:

};
#endif // BombPlant_H_
#ifndef HealPlant_H_
#define HealPlant_H_
class HealPlant:public Plant
{
public:

    HealPlant(std::fstream &ifs)
    {
       // DerivedPlant(ifs);
    };
    ~HealPlant() {};
private:
};
#endif // HealPlant_H_
