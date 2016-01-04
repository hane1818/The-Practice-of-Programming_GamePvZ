#include"Zombie.h"
#include"Land.h"
#include"Map.h"
#include<cstdlib>
#include<time.h>

using namespace std;
int main()
{
    srand(time(0));
    int lands = 0;
    cout << "Number of lands on the map.";
    cin >> lands;
    cout << "Number of zombies.";
    cin >> Zombie::TotalNum;

    Map map(lands);
    Player p;
    Zombie * z = new Zombie[Zombie::TotalNum];
    CoinPlant c;
    /*Set pos*/
    p.Move(rand()%lands);
    for(int i=0;i<Zombie::TotalNum;i++)
        z[i].Move(rand()%lands);

    /*Display*/
    cout << "Before"<< endl;
    map.Display(p,z);


    delete []z;
    /*Land a;
    CoinPlant b;
    CoinPlant c;
    for(int i=0; i<2; i++)
    {
        if(a.IsEmpty())
        {
            a.Planting(b);
            std::cout << "Land A is planted b" << std::endl;
        }
        else
        {
            std::cout << "Land A was planted b" << std::endl;
        }
    }*/

    /*Zombie * a = new Zombie[ZOMBIE]();
    Zombie::TotalNum = ZOMBIE;
    for(int i=0; i<ZOMBIE; i++)
    {
        a[i].Move(rand()%LAND);
        std::cout << a[i].Pos() << " ";
        std::cout << a[i];
    }

    for(Zombie::TotalNum; Zombie::TotalNum > 0;)
    {
        for(int i=0; i<Zombie::TotalNum; i++)
        {
            int damage = rand()% 20;
            a[i].Damage(damage);
            std::cout << "[" << i << "]" << " " << a[i];
            if( !a[i].isAlive())
            {
                Zombie::TotalNum --;
                std::cout << "It is dead" << std::endl;
            }
        }
        system("pause");
    }*/

    return 0;
}
