#ifndef PLAYER_H_
#define PLAYER_H_
class Player
{
public:
    Player()=default;
    Player(int Money):Money_(Money){};
    ~Player(){};
    void Move(const int index)
    {
        Position_=index;
    }
    const int Pos(){return Position_;}
    const int Money(){return Money_;}
    void CostMoney(const int cost){Money_-=cost;}
private:
    int Money_=150;
    int Position_=0;
};
#endif // PLAYER_H_
