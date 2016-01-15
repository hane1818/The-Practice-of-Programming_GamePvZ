#include <sstream>
#include <stdlib.h>
#include"Plant.h"
using namespace std;
int BombPlant::deadNum=0;
std::ostream & operator << (std::ostream &os, const Plant &p)
{
    os<<p.Name()<<" "<<"HP: "<<p.Hp();
    if(p.Round()>0)
    {
        os<<"("<<p.Round()<<" more visit(s) )";
    }
    return os;
}
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
    name_=buffer[1];
    price_=atoi(buffer[2].substr(1,buffer[2].size()).c_str());
    hp_=atoi(buffer[3].c_str());
    initialHp_=hp_;
}
CoinPlant::CoinPlant(std::fstream & ifs)
{
    if(ifs)
    {
        std::string buffer[6];
        readFile(ifs,buffer);
        round_=atoi(buffer[4].c_str());
        giveMoney_=atoi(buffer[5].c_str());
        roundtimes_=0;
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
        damage_=atoi(buffer[4].c_str());
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
        hpBack_=atoi(buffer[4].c_str());
    }
    else
    {
        std::cout<<"Cannot read."<<std::endl;
    }
}
