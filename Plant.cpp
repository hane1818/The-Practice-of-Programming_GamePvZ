#include"Plant.h"
using namespace std;
void Plant::DerivedPlant(fstream & ifs,string buffer[])
{
    std::string str;
    getline(ifs,str);
    std::stringstream ss(str);
    string sub;
    int i=0;
    while(getline(ss,sub,' '))
    {
        buffer[i]=sub;
        cout<<"[ "<<buffer[i]<<" ]";
        ++i;
    }
    cout<<endl;
}
