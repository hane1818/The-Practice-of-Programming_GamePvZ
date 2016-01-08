#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
//#include <vector>
//#include <fstream>
#include "Map.h"
#include "Zombie.h"
#include "Player.h"

using namespace std;

int main()
{
    //game start
    cout << " -----------------------------" << endl
         << "|     Plants v.s Zombies      |" << endl
         << " -----------------------------" << endl;
    constexpr int LAND_DEFAULT=8;
    constexpr int LAND_MAX=10;
    constexpr int LAND_MIN=1;
    constexpr int ZOMBIE_DEFAULT=3;
    constexpr int ZOMBIE_MAX=10;
    constexpr int ZOMBIE_MIN=1;

    string input;
    //initialize game setting
    cout << "Number of lands on the map (" << LAND_MIN << "-" << LAND_MAX << ", default: " << LAND_DEFAULT <<")...>";
    int value = LAND_DEFAULT;
    getline(cin, input);
    if(!input.empty())
    {
        istringstream stream( input );
        stream >> value;
        if(value > LAND_MAX) value = LAND_MAX;
        if(value < LAND_MIN) value = LAND_MIN;
    }
    const int LANDS=value;

    cout << "Number of zombies on the map (" << ZOMBIE_MIN << "-" << ZOMBIE_MAX << ", default: "<< ZOMBIE_DEFAULT <<")...>";
    value=ZOMBIE_DEFAULT;
    getline(cin, input);
    if(!input.empty())
    {
        istringstream stream( input );
        stream >> value;
        if(value > ZOMBIE_MAX) value = ZOMBIE_MAX;
        if(value < ZOMBIE_MIN) value = ZOMBIE_MIN;
    }
    const int ZOMBIES=value;

    //game rules
    cout << "=============================================================================" << endl
         << "Plants vs. Zombies Rule:" << endl
         << endl
         << "How to win:" << endl
         << "  (1) All zombies are dead." << endl
         << "  (2) At least one plant is live." << endl
         << "  (3) The number of dead bomb plants cannot exceed the number of zombies." << endl
         << endl
         << "How to lose:" << endl
         << "  All plants are dead." << endl
         << "=============================================================================" << endl;
    system("pause");
    system("cls");

    //game start
    //construct
    Player *player = new Player;
    Zombie *zombie = new Zombie[ZOMBIES];
    Zombie::TotalNum = ZOMBIES;
    Map *map = new Map(LANDS);
    /*vector<Plant*> plant;
    ifstream fin=open("plants.txt");
    while(!fin.eof())
    {
        char type;
        fin << type;
        if(fin.eof()) break;
        Plant *tmp = nullptr;
        switch(type)
        {
        case 'C':
            {
                tmp = new CoinPlant(fin);
            }
        case 'S':
            {
                tmp = new HornPlant(fin);
            }
        case 'B':
            {
                tmp = new BombPlant(fin);
            }
        case 'H':
            {
                tmp = new HealPlant(fin);
            }
        default:
            continue;
        }
        if(tmp)
        {
            plant.push_back(tmp);
        }
    }*/

    map->Display(*player, zombie);  //cout << *map << endl;
    cout << "------------------------------------------------" << endl;
    cout << "Zombie information:" << endl;
    for(int i=0;i<ZOMBIES;i++)
    {
        cout << '[' << i << "] " << zombie[i];
    }
    cout << endl << "================================================" << endl;

    /*while(true)
    {
        for(int i=0;i<plant.size();++i)
        {
            cout << '[' << i << "] " ;
            switch(plant[i]->type())
            {
                case 'C':
                    cout << dynamic_cast<CoinPlant *>(plant[i]);
                case 'S':
                    cout << dynamic_cast<HornPlant *>(plant[i]);
                case 'B':
                    cout << dynamic_cast<BombPlant *>(plant[i]);
                case 'H':
                    cout << dynamic_cast<HealPlant *>(plant[i]);
            }
            cout << endl;
        }
        cout << endl << *player;
        int choice = plant.size();
        cout << ":    Enter your choice (" << plant.size() << " to give up, default: " << choice << ")...>";

        if(choice=plant.size()) break;
        int cost=0;
        string plantname;
        switch(plant[choice].type())
        {
        case 'C':
            CoinPlant *tmp = new CoinPlant(*dynamic_cast<CoinPlant *>(plant[choice]))
            land->plant(tmp);
            plantname="CoinPlant";
            cost=tmp->price();
        case 'S':
            HornPlant *tmp = new HornPlant(*dynamic_cast<CoinPlant *>(plant[choice]))
            land->plant(tmp);
            plantname="HornPlant";
            cost=tmp->price();
        case 'B':
            BombPlant *tmp = new BombPlant(*dynamic_cast<CoinPlant *>(plant[choice]));
            land->plant(tmp);
            plantname="BombPlant";
            cost=tmp->price();
        case 'H':
            HealPlant *tmp = new HealPlant(*dynamic_cast<CoinPlant *>(plant[choice]));
            land->plant(tmp);
            plantname="HealPlant";
            cost=tmp->price();
        }
        if(player->money() >= cost)
        {
            cout << "You have planted " << plantname << " at land 7 !";
            break;
        }
        else
        {
            cout << "Not enough money! Please input again.";
        }
    }*/

    // destruct
    //while(!plant.empty())
    //    delete plant.pop_back();
    delete player;
    delete map;
    delete [] zombie;

    return 0;
}
