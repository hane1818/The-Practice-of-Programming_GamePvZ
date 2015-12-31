#include"Zombie.h"
#include"land.h"
#include<cstdlib>
#include<time.h>
int main()
{
    srand(time(0));
    int ZOMBIE = 5;
    int LAND = 10;
    int BasicHurt = 20;

    Land a;
    CoinPlant b;
    a.Planting(b);
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
