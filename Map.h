#ifndef MAP__
#define MAP__

#include<cstdio>
#include<iostream>

class Map
{

private:
    Land * map_;
    size_t size_;
public:
    Map(int size):map_(nullptr),size_(size)
    {
        map_ = new Land[size];
    };
    ~Map()
    {
        delete []map_;
        map_ = nullptr;
        size_ = 0;
    };
    Land * GetLand(const int index)
    {
        return &map_[index];
    }
    void Display(Player &p , Zombie * z)
    {
        for(int i=0;i<size_;i++)
        {
            std::cout << "[" << i << "]{";
            std::cout << ((p.Pos()==i) ? "*" : " ");
            for(int j=0;j<Zombie::TotalNum;j++)
            {
                if((z[j].Pos() == i))
                    std::cout << j;
                else
                    std::cout << " ";
            }
            std::cout << "}";
            GetLand(i)->Print();
            std::cout << std::endl;
        }
    }
};

#endif // MAP

