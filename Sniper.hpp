#pragma once

#include <vector>
#include <stdexcept>
#include "Soldier.hpp"

using namespace std;
//using namespace WarGame;
namespace WarGame {

class Sniper  : public Soldier{
    public: 
Sniper(){}
~Sniper(){}

Sniper(int t) {
 const int health=100;  
 damage=50;
 life=100;
 team =t;
 type=Sniper_solider;
}

void attack(std::vector<std::vector<Soldier*>>& board ,pair <int,int> loction);
 void fullAttack(std::vector<std::vector<Soldier*>>& board ,pair <int,int> loction) override;
pair<int,int> Strongest_Soldier(std::vector<std::vector<Soldier*>>& board,pair <int,int> loction);};

}