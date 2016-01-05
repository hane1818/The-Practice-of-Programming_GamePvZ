#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include"Plant.h"
using namespace std;

int main()
{
    vector<Plant*> plant;
    fstream fin;
    fin.open("plants.txt",fstream::in);
    if(fin)
    {
        string str;
        while(fin>>str)
        {
            Plant*tmp=nullptr;
            switch(str[0])
            {
            case 'C':
                tmp = new CoinPlant(fin);
                break;
            case 'S':
                tmp = new HornPlant(fin);
                break;
            case 'B':
                tmp = new BombPlant(fin);
                break;
            case 'H':
                tmp = new HealPlant(fin);
                break;
            default:
                break;
            }
            if(tmp)
            {
                plant.push_back(tmp);
            }
        }
    }
    cout<<*plant[3]<<" *****"<<endl;
    plant[3]->Print();
    cout<<endl;
    while(!plant.empty())
    {
        delete plant.back();
        plant.pop_back();
    }
    return 0;
}
