#include "Game.h"
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

Game::Game(int lands, int zombies):numOfLand_(lands),numOfZombie_(zombies),
    player_(new Player),zombie_(new Zombie[numOfZombie_]),map_(new Map(numOfLand_))
{
    Map *m;
    if(numOfLand_ < LAND_MIN)
    {
        numOfLand_=LAND_MIN;
        m=new Map(numOfLand_);
        delete map_;
        map_=m;
    }
    else if (numOfLand_ > LAND_MAX)
    {
        numOfLand_=LAND_MAX;
        m=new Map(numOfLand_);
        delete map_;
        map_=m;
    }

    Zombie *z;
    if(numOfZombie_ < ZOMBIE_MIN)
    {
        numOfZombie_=ZOMBIE_MIN;
        z=new Zombie[numOfZombie_];
        delete [] zombie_;
        zombie_=z;
    }
    else if (numOfZombie_ > ZOMBIE_MAX)
    {
        numOfZombie_=ZOMBIE_MAX;
        z=new Zombie[numOfZombie_];
        delete [] zombie_;
        zombie_=z;
    }
    initPlant();
    player_->Move(rand()%numOfLand_);
    for(int i=0; i<numOfZombie_; ++i)
        if(zombie_[i].isAlive())
            zombie_[i].Move(rand()%numOfLand_);
}

Game::~Game()
{
    delete player_;
    delete [] zombie_;
    delete map_;
    while(!plant_.empty())
    {
        delete plant_.back();
        plant_.pop_back();
    }
}

void Game::doPlayer() const
{
    static int choice=plant_.size();
    int position = player_->Pos();
    Land * land = map_->GetLand(position);
    if(!land->IsEmpty())
    {
        Plant *p = land->GetPlant();
        int visit = p->Visit(*player_);
        if(visit < 0)
        {
            map_->Healing(-visit);
            cout << "All your plants have recovered "<< -visit << " HP!" << endl;
        }
        else if (visit)
        {
            cout << "You have earned $" << visit << "! Now you have $" << player_->Money();
        }
    }
    else
    {
        if (!enoughMoney())
        {
            cout << "You don't have enough money to plant anything" << endl;
        }
        else
        {
            do{
                printPlant();
                printPlayer();
                cout << ":\tEnter your choice (" << plant_.size() << " to give up, default: " << choice << ")...>";
                string input;
                getline(cin, input);
                if(!input.empty())
                {
                    istringstream stream( input );
                    stream >> choice;
                    if(choice > plant_.size() || choice < 0) choice = plant_.size();
                }
                if(choice != plant_.size())
                {
                    map_->GetLand(player_->Pos())->Planting(*player_, *plant_[choice]);
                    cout << "You have planted " << plant_[choice]->Name() << " at land " << player_->Pos() << " !" << endl;
                    break;
                }
                else
                {
                    cout << "You give up!" << endl;
                    break;
                }
                if((choice != plant_.size() && plant_[choice]->Price() > player_->Money()))
                    cout << "Not enough money! Please input again!" << endl;
                system("pause");
            }
            while(true);
        }
    }
}

void Game::doZombie(int z_ind) const
{
    int position = rand()%numOfLand_;
    zombie_[z_ind].Move(position);
    cout << "Zombie [" << z_ind << "] moves to land " << position << "." << endl;
    Land * land = map_->GetLand(position);
    if(!land->IsEmpty())
    {
        Plant *p = land->GetPlant();
        int visit = p->Visit(zombie_[z_ind]);
        if(visit)
        {
            cout << p->Name() << " gives " << visit << " damage to the zombie!" << endl;
        }
        cout << "Zombie eats plant " << p->Name() << " and cause damage " << zombie_[z_ind].Attack() << endl;
        if(!zombie_[z_ind].isAlive())
            cout << "Zombie is killed!" << endl;
        if(!p->isAlive())
        {
            land->Dead();
            cout << "Plant " << p->Name() << " is dead!" << endl;
        }
    }
}

void Game::printPlant() const
{
    for(size_t i=0; i<plant_.size(); ++i)
    {
        cout << "[" << i << "] " ;
        plant_[i]->Print();
        cout << endl;
    }
}
void Game::printZombies() const
{
    for(int i=0; i<numOfZombie_; ++i)
    {
        if(zombie_[i].isAlive())
            cout << '[' << i << "] " << zombie_[i];
    }
}
void Game::printPlayer() const
{
    cout << endl << "Player $" << player_->Money() ;
}

void Game::movePlayer(int pos) const
{
    player_->Move(limitStep(pos));
}
void Game::moveZombie(Zombie & z, int pos) const
{
    z.Move(limitStep(pos));
}
int Game::limitStep(int pos) const
{
    if(pos > numOfLand_-1)
        return numOfLand_-1;
    else if (pos < 0)
        return 0;
    else
        return pos;
}

bool Game::endGame() const
{
    if (map_->IsNonPlant())
    {
        cout << endl << "Oh no... You have no plant on the map ...." << endl;
        return true;
    }
    else if (BombPlant::deadNum > numOfZombie_/2)
    {
        cout << endl << "You lose the game since you cannot use that many bomb plants!" << endl;
        return true;
    }
    else if (allZombiesDie())
    {
        cout << endl << "Congratulations! You have killed all zombies!" << endl;
        return true;
    }
    return false;
}

void Game::initPlant()
{
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
                plant_.push_back(tmp);
            }
        }
    }
}

bool Game::allZombiesDie() const
{
    for(int i=0; i<numOfZombie_ && !zombie_[i].isAlive(); ++i)
        return (i==numOfZombie_-1);
}

bool Game::enoughMoney() const
{
    for (Plant* p : plant_)
        if (p->Price() <= player_->Money()) return true;
    return false;
}

std::ostream & operator << (std::ostream & os, const Game & game)
{
    game.map_->Display(*game.player_, game.zombie_);
    cout << "------------------------------------------------" << endl;
    cout << "Zombie information:" << endl;
    for(int i=0; i<game.numOfZombie_; ++i)
    {
        if(game.zombie_[i].isAlive())
            cout << '[' << i << "] " << game.zombie_[i];
    }
    cout << "================================================" << endl;
}
