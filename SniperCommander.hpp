#pragma once
#include <vector>
#include <stdexcept>
#include "Sniper.hpp"
using namespace std;
using namespace WarGame;

class SniperCommander  : public Sniper{
    public: 
SniperCommander() {}
~SniperCommander() {}
SniperCommander(int t) {
 const int health=120;  
 damage=100;
 life=120;
 team =t;
}

void fullAttack(std::vector<std::vector<Soldier*>>& board ,pair <int,int> loction)override ;
void attack(std::vector<std::vector<Soldier*>>& board ,pair <int,int> loction) ;
pair<int,int> Strongest_Soldier(std::vector<std::vector<Soldier*>>& board,pair <int,int> loction)  ;
};

