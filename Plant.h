#include<string>
#include <sstream>
#include<iostream>
#include <fstream>
#include <stdlib.h>
//==========================================================//
#ifndef PLANT_H_
#define PLANT_H_
#include <iostream>
#include <string>
#include <fstream>
class Plant
{
    friend std::ostream & operator << (std::ostream &os, const Plant &p)
    {
        os<<p.name_<<" "<<"HP: "<<p.hp_;
        return os;
    }

public:
    Plant()=default;
    Plant(const std::string name,const int price=0,const int hp=0):name_(name),price_(price),hp_(hp)
    {
        //std::cout<<name_<<" "<<price_<<" "<<hp_<<" ====== "<<std::endl;
    };
    Plant(const Plant &p):Plant(p.name_,p.price_,p.hp_) {};
    virtual ~Plant()
    {
        std::cout<<"~Plant()"<<std::endl;
    };
    virtual void Damage(const int hurt) {hp_-=hurt;}
    bool isAlive()const {return (hp_>0);}
    const std::string Name()const {return name_;}
    const int Price()const {return price_;}
    const int Hp()const {return hp_;}
    const char Type()const {return type_;}
    virtual void Print()const =0;
    virtual const int Round()const =0;
    virtual const int GiveMoney()const =0;
    virtual const int Damage()const =0;
    virtual const int HpBack()const =0;
protected:
    void readFile(std::fstream & ifs,std::string buffer[]) ;
    char type_='/0';
    std::string name_;
    int price_=0;
    int hp_=0;
};
#endif // PLANT_H_
//==================================================================//
#ifndef CoinPlant_H_
#define CoinPlant_H_
class CoinPlant:public Plant
{

public:
    CoinPlant()=default;
    CoinPlant(std::fstream & ifs);
    CoinPlant(const std::string name,const int price,const int hp,const int round,const int giveMoney):Plant(name,price,hp),round_(round),giveMoney_(giveMoney) {}
    CoinPlant(const CoinPlant &c):CoinPlant(c.name_,c.price_,c.hp_,c.round_,c.giveMoney_) {}
    ~CoinPlant()
    {
        std::cout<<"~CoinPlant()"<<std::endl;
    }
    virtual void Print()const
    {
        std::cout<<name_<<" $"<<price_<<" HP: "<<hp_<<" - gives $"<<giveMoney_<<" every "<<round_<<" rounds";
    }
    const int Round()const {return round_;}
    const int GiveMoney()const {return giveMoney_;}
private:
    int round_=0;
    int giveMoney_=0;
};
#endif // CoinPlant_H_
//==================================================================//
#ifndef HornPlant_H_
#define HornPlant_H_
class HornPlant:public Plant
{
public:

    HornPlant()=default;
    HornPlant(std::fstream & ifs);
    HornPlant(const std::string name,const int price,const int hp,const int damage):Plant(name,price,hp),damage_(damage) {}
    HornPlant(const HornPlant &s):HornPlant(s.name_,s.price_,s.hp_,s.damage_) {}
    ~HornPlant()
    {
        std::cout<<"~HornPlant"<<std::endl;
    }
    virtual void Print()const
    {
        std::cout<<name_<<" $"<<price_<<" HP: "<<hp_<<" - gives $"<<damage_<<" damage points";
    }
    const int Damage()const {return damage_;}
private:
    int damage_=0;
};
#endif // HornPlant_H_
//==================================================================//
#ifndef BombPlant_H_
#define BombPlant_H_
class BombPlant:public Plant
{
public:
    BombPlant()=default;
    BombPlant(std::fstream & ifs);
    BombPlant(const std::string name,const int price,const int hp):Plant(name,price,hp){}
    BombPlant(const BombPlant &b):BombPlant(b.name_,b.price_,b.hp_) {}
    ~BombPlant()
    {
        std::cout<<"~BombPlant"<<std::endl;
    }
    static int deadNum;
    virtual void Print()const
    {
        std::cout<<name_<<" $"<<price_<<" HP: "<<hp_<<" - gives $"<<hp_<<" damage points";
    }
    virtual void Damage(const int hurt)
    {
        hp_=0;
        deadNum++;
    }
};
#endif // BombPlant_H_
//==================================================================//
#ifndef HealPlant_H_
#define HealPlant_H_
class HealPlant:public Plant
{
public:

   HealPlant()=default;
    HealPlant(std::fstream & ifs);
    HealPlant(const std::string name,const int price,const int hp,const int hpBack):Plant(name,price,hp),hpBack_(hpBack){}
    HealPlant(const HealPlant &h):HealPlant(h.name_,h.price_,h.hp_,h.hpBack_) {}
    ~HealPlant()
    {
        std::cout<<"~HealPlant"<<std::endl;
    }
    virtual void Print()const
    {
        std::cout<<name_<<" $"<<price_<<" HP: "<<hp_<<" - gives all your plants "<<hpBack_<<" HP back.";
    }
    const int HpBack()const {return hpBack_;}
private:
    int hpBack_=0;
};
#endif // HealPlant_H_
