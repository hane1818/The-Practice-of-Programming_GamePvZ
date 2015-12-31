#include"Plant.h"
using namespace std;
string* Plant::DerivedPlant(fstream & ifs)
{
    std::string str;
    getline(ifs,str);
    std::stringstream ss(str);
    string sub;
    string buffer[10];
    int i=0;
    while(getline(ss,sub,' '))
    {
        buffer[i]=sub;
        cout<<"[ "<<buffer[i]<<" ]";
        ++i;
    }
    cout<<endl;
    return buffer;


}
