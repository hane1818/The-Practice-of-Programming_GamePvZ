#ifndef ZOMBIE__
#define ZOMBIE__

#include<cstdio>
#include<iostream>
class Player
{
private:
    int pos_;
    int money_;
public:
    Player():pos_(0){};
    const int Pos()const{return pos_;};
    void Move(const int i){pos_ = i;};
};

class Zombie
{
private:
    int hp_;
    int attack_;
    int pos_;
public:
    static int TotalNum;
    Zombie():hp_(30),attack_(15),pos_(0){};
    ~Zombie(){};
    const int Hp() const { return hp_;};
    const int Attack() const {  return attack_;};
    const int Pos() const { return pos_;};
    void Move(const int index){  pos_ = index;};
    void Damage(const int damage){ hp_ -= damage;};
    bool isAlive(){return (hp_ > 0);};
};
int Zombie::TotalNum;

std::ostream & operator << (std::ostream & os, const Zombie &x)
{
    os << "Damage: " << x.Attack() << " HP:";
    for(int i = 0;i<x.Hp();i++)
    {
        os << "*";
    }
    os << std::endl;
}

#endif // ZOMBIE
