#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <ctime>
#include "Map.h"
#include "Zombie.h"
#include "Player.h"
#include "Plant.h"

using namespace std;

bool allZombiesDie(const Zombie * zombie);
bool enoughMoney(const vector<Plant*> & plant, const Player * player);
void printInfor(const Map & map, const Player & player, const Zombie * zombie);
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

    //construct
    srand(time(0));     // random number seed
    Player *player = new Player;
    Zombie *zombie = new Zombie[ZOMBIES];
    Zombie::TotalNum = ZOMBIES;
    Map *map = new Map(LANDS);
    vector<Plant*> plant;
    fstream fin("plants.txt", fstream::in);
    string str;
    if(fin)
    {
        while(fin >> str)
        {
            Plant *tmp = nullptr;
            switch(str[0])
            {
            case 'C':
            {
                tmp = new CoinPlant(fin);
                break;
            }
            case 'S':
            {
                tmp = new HornPlant(fin);
                break;
            }
            case 'B':
            {
                tmp = new BombPlant(fin);
                break;
            }
            case 'H':
            {
                tmp = new HealPlant(fin);
                break;
            }
            default:
                continue;
            }
            if(tmp)
            {
                plant.push_back(tmp);
            }
        }
    }

    player->Move(rand()%LANDS);
    for (int i=0; i<ZOMBIES; ++i)
        zombie[i].Move(rand()%LANDS);
    int choice = plant.size();
    while(true)
    {
        printInfor(*map, *player, zombie);
        do
        {
            if (!enoughMoney(plant, player))
            {
                cout << "You don't have enough money to plant anything" << endl;
                break;
            }
            else if (map->GetLand(player->Pos())->IsEmpty())
            {
                for(size_t i=0; i<plant.size(); ++i)
                {
                    cout << "[" << i << "] " ;
                    plant[i]->Print();
                    cout << endl;
                }
                cout << endl << "Player $" << player->Money() ;
                cout << ":\tEnter your choice (" << plant.size() << " to give up, default: " << choice << ")...>";
                getline(cin, input);
                if(!input.empty())
                {
                    istringstream stream( input );
                    stream >> choice;
                    if(choice > plant.size() || choice < 0) choice = plant.size();
                }
                if(choice != plant.size())
                {
                    map->GetLand(player->Pos())->Planting(*player, *plant[choice]);
                    cout << "You have planted " << plant[choice]->Name() << " at land " << player->Pos() << " !" << endl;
                }
                break;
            }
            if(choice != plant.size() && plant[choice]->Price() > player->Money())
            {
                cout << "Not enough money! Please input again!" << endl;
                system("pause");
            }
        }
        while (true);

        int position;
        for (int i=0; i<ZOMBIES; ++i)
        {
            if (zombie[i].isAlive())
            {
                position = rand()%LANDS;
                zombie[i].Move(position);
                cout << "Zombie [" << i << "] moves to land " << position << "." << endl;
                Land * land = map->GetLand(position);
                if(!land->IsEmpty())
                {
                    Plant *p = land->GetPlant();
                    p->Visit(zombie[i]);
                    if(p->Attack())
                    {
                        //zombie[i].Damage(p->Attack());
                        cout << p->Name() << " gives " << p->Attack() << " damage to the zombie!" << endl;
                    }
                    //p->Damage(zombie[i].Attack());
                    cout << "Zombie eats plant " << p->Name() << " and cause damage " << zombie[i].Attack() << endl;
                    if(!zombie[i].isAlive())
                        cout << "Zombie is killed!" << endl;
                    if(!p->isAlive())
                        cout << "Plant " << p->Name() << " is dead!" << endl;
                }
                system("pause");
            }
        }
        position = rand()%LANDS;
        player->Move(position);
        Land *l = map->GetLand(position);
        if(!l->IsEmpty())
        {
            Plant *p = l->GetPlant();
            if(p->HpBack())
            {
                cout << "oh no?" << endl;
                map->Healing(p->HpBack());
                cout << "All your plants have recovered "<< p->HpBack() << " HP!" << endl;
            }
        }
        system("pause");

        // end game condition
        if (map->IsNonPlant())
        {
            cout << "Oh no... You have no plant on the map ...." << endl;
        }
        else if (BombPlant::deadNum >= ZOMBIES/2)
        {
            cout << "You lose the game since you cannot use that many bomb plants!" << endl;
        }
        else if (allZombiesDie(zombie))
        {
            cout << "Congratulations! You have killed all zombies!" << endl;
        }
        system("cls");
        //break;
    }

    // destruct
    while(!plant.empty())
    {
        delete plant.back();
        plant.pop_back();
    }
    delete player;
    delete map;
    delete [] zombie;

    return 0;
}

bool allZombiesDie(const Zombie * zombie)
{
    for(int i=0; i<Zombie::TotalNum && !zombie[i].isAlive(); ++i)
        return (i==Zombie::TotalNum-1);
}

bool enoughMoney(const vector<Plant*> & plant, const Player * player)
{
    for (Plant* p : plant)
        if (p->Price() <= player->Money()) return true;
    return false;
}

void printInfor(const Map & map, const Player & player, const Zombie * zombie)
{
    map.Display(player, zombie);
    cout << "------------------------------------------------" << endl;
    cout << "Zombie information:" << endl;
    for(int i=0; i<Zombie::TotalNum; ++i)
    {
        if(zombie[i].isAlive())
            cout << '[' << i << "] " << zombie[i];
    }
    cout << "================================================" << endl;
}
