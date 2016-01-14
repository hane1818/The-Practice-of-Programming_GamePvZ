#include"Zombie.h"
#include"Plant.h"
#include"Player.h"
#include"Land.h"
#include"Map.h"
#include<cstdlib>
#include<time.h>

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
    for(int i=0;i<Zombie::TotalNum;i++)
        z[i].Move(rand()%lands);

    /*Display*/
    if(map.IsNonPlant())
    {
        cout << "The map is so clear!" << endl;
    }
    map.Display(p,z);
    /*Plainting*/
    HealPlant x("HealPlant",50,50,10);
    for(int i=0;i<COUNT;i++)
    {
        if(p.Money()>0)
        {
            if(map.GetLand(p.Pos())->IsEmpty())
            {
                cout << "p's money:" << p.Money() << endl;
                map.GetLand(p.Pos())->Planting(p,x);
                cout << "p plant a plant." << x.Name() << endl;
            }
        }
        cout << "p move to " << map.Rand(p) << endl<< endl;
        for(int j=0;j<Zombie::TotalNum;j++)
        {
            cout << "z[" << j << "] move to " << map.Rand(z[j]) << endl;
        }
        map.Display(p,z);
        system("pause");
        system("cls");
    }
    delete []z;
    return 0;
}
