#ifndef ZOMBIE__
#define ZOMBIE__

#include <cstdio>
#include <iostream>

class Zombie
{
private:
    int pos_;
    int hp_;
    int attack_;
public:
    static int TotalNum;
    Zombie():pos_(0),hp_(50),attack_(15){};
    Zombie(int position):pos_(position){};
    Zombie(const int pos,const int hp,const int attack):pos_(pos),hp_(hp),attack_(attack){};
    Zombie(Zombie & z){};
    Zombie & operator = (const Zombie & rhs)
    {
        pos_ = rhs.pos_;
        hp_ = rhs.hp_;
        attack_ = rhs.attack_;
        return (*this);
    }
    ~Zombie(){};
    const int Hp() const { return hp_;};
    const int Attack() const {  return attack_;};
    const int Pos() const { return pos_;};
    void Move(const int index){  pos_ = index;};
    void Damage(const int damage){ hp_ -= damage;};
    bool isAlive()const {return (hp_ > 0);};
};

#endif // ZOMBIE
