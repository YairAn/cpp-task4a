#pragma once

#include <vector>
#include <stdexcept>
using namespace std;
namespace WarGame {

class Soldier{
    public: 
        int health;
        int damage ;
        int life;
        int team;

Soldier():health(100),life(100),damage(10){}

virtual ~Soldier(){
}
 void attack(std::vector<std::vector<Soldier*>>& board ,pair <int,int> loction);
 virtual void fullAttack (std::vector<std::vector<Soldier*>>& board,pair <int,int> loction){}
 pair<int,int> CloserSoldier(std::vector<std::vector<Soldier*>>& board,pair <int,int> loction);

};

}