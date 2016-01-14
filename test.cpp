#include"Zombie.h"
#include"Plant.h"
#include"Player.h"
#include"Land.h"
#include"Map.h"
#include<cstdlib>
#include<time.h>

bool allZombiesDie(const Zombie * zombie);
void printInfor(const Map & map, const Player & player, const Zombie * zombie);

using namespace std;
int main()
{
    srand(time(0));
    constexpr int COUNT = 5;
    int lands = 0;
    cout << "Number of lands on the map.";
    cin >> lands;
    cout << "Number of zombies.";
    cin >> Zombie::TotalNum;

    Map map(lands);
    Player p;
    Zombie * z = new Zombie[Zombie::TotalNum];

    /*Set pos*/
    p.Move(rand()%lands);
    for(int i=0; i<Zombie::TotalNum; i++)
        z[i].Move(rand()%lands);

    /*Display*/
    map.Display(p,z);
    cout << map.IsNonPlant() << endl;
    /*Plainting*/
    HornPlant x("HornPlant",50,50,10);
    for(int i=0; i<lands; i++)
    {
        if(p.Pos()==i)
            map.GetLand(i)->Planting(p,x);
    }
    cout << map.IsNonPlant() << endl;
    for(int i=0;i<10;i++)
    {
        map.GetLand(p.Pos())->GetPlant()->Damage(z[0].Attack());
        if( map.GetLand(p.Pos())->Dead() )
        {
            cout << "Plant dead!" << endl;
            cout << map.IsNonPlant() << endl;
            break;
        }
    }
    delete []z;
    return 0;
}
