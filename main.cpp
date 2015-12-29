#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>

using namespace std;

int main()
{
    cout << "-------------------------------" << endl
         //<< "|                             |" << endl
         << "|     Plants v.s Zombies      |" << endl
         //<< "|                             |" << endl
         << "-------------------------------" << endl;
    constexpr int LAND_DEFAULT=8;
    constexpr int LAND_MAX=10;
    constexpr int LAND_MIN=1;
    constexpr int ZOMBIE_DEFAULT=3;
    constexpr int ZOMBIE_MAX=10;
    constexpr int ZOMBIE_MIN=1;

    string input;

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

    return 0;
}
