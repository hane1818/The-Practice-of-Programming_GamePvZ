#ifndef PLAYER_H_
#define PLAYER_H_
#include <iostream>

class Player
{
public:
    Player()=default;
    Player(int Money):Money_(Money){}
    ~Player(){}
    void Move(const int index) { Position_=index; }
    const int Pos() const { return Position_; }
    const int Money() const { return Money_; }
    void CostMoney(const int cost) { Money_-=cost; }
private:
    int Money_=150;
    int Position_=0;
};

inline std::ostream & operator << (std::ostream &os, const Player &p)
{
    os << "Player $" << p.Money();
    return os;
}
#endif // PLAYER_H_
