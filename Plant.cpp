#include <sstream>
#include <cstdlib>
#include"Plant.h"
using namespace std;
int BombPlant::deadNum=0;
void Plant::readFile(fstream & ifs,string buffer[])
{
    std::string str;
    getline(ifs,str);
    std::stringstream ss(str);
    string sub;
    int i=0;
    while(getline(ss,sub,' '))
    {
        buffer[i]=sub;
        ++i;
    }
    std::string name=buffer[1];
    int price=atoi(buffer[2].substr(1,buffer[2].size()).c_str());
    int hp=atoi(buffer[3].c_str());
    name_=name;
    price_=price;
    hp_=hp;
}
CoinPlant::CoinPlant(std::fstream & ifs)
{
    if(ifs)
    {
        std::string buffer[6];
        readFile(ifs,buffer);
        int round=atoi(buffer[4].c_str());
        int giveMoney=atoi(buffer[5].c_str());
        type_='C';
        round_=round;
        giveMoney_=giveMoney;
    }
    else
    {
        std::cout<<"Cannot read."<<std::endl;
    }
}
HornPlant::HornPlant(std::fstream & ifs)
{
    if(ifs)
    {
        std::string buffer[6];
        readFile(ifs,buffer);
        type_='S';
        int damage=atoi(buffer[4].c_str());
        damage_=damage;
    }
    else
    {
        std::cout<<"Cannot read."<<std::endl;
    }
}
BombPlant::BombPlant(std::fstream & ifs)
{
    if(ifs)
    {
        std::string buffer[6];
        readFile(ifs,buffer);
        type_='B';
    }
    else
    {
        std::cout<<"Cannot read."<<std::endl;
    }
}
HealPlant::HealPlant(std::fstream & ifs)
{
    if(ifs)
    {
        std::string buffer[6];
        readFile(ifs,buffer);
        type_='H';
        int hpBack=atoi(buffer[4].c_str());
        hpBack_=hpBack;
    }
    else
    {
        std::cout<<"Cannot read."<<std::endl;
    }
}

