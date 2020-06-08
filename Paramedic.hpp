#pragma once
#include <vector>
#include <stdexcept>
#include "Soldier.hpp"
using namespace std;

using namespace WarGame;
class Paramedic : public Soldier{
    public: 
   Paramedic(){}
      ~Paramedic(){
   }
Paramedic(int t) {
 const int health=100;  
 //damage=0;
 life=100;
 team =t;
 type= P_Solidier;
}

void attack(std::vector<std::vector<Soldier*>>& board ,pair <int,int> loction);
 void fullAttack(std::vector<std::vector<Soldier*>>& board ,pair <int,int> loction) override;
std::vector <Soldier*> FindFriends(std::vector<std::vector<Soldier*>>& board,pair <int,int> loction);



};

