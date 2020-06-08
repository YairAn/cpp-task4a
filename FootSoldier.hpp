#pragma once
#include <vector>
#include <stdexcept>
#include "Soldier.hpp"
using namespace std;
using namespace WarGame;


class FootSoldier : public Soldier{
    public: 
   FootSoldier(){}
      ~FootSoldier(){
   }

 
FootSoldier(int t) {
 const int health=100;  
 damage=10;
 life=100;
 team =t;
 type=F_Soldier;
}

void attack(std::vector<std::vector<Soldier*>>& board ,pair <int,int> loction);
 void fullAttack(std::vector<std::vector<Soldier*>>& board ,pair <int,int> loction) override;
pair<int,int> CloserSoldier(std::vector<std::vector<Soldier*>>& board,pair <int,int> loction);



};

//}