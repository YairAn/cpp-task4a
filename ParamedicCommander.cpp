//#pragma once
#include <vector>
#include <stdexcept>
#include<cmath>
#include "ParamedicCommander.hpp"
using namespace std;
using namespace WarGame;

void ParamedicCommander::fullAttack(std::vector<std::vector<Soldier*>>& board ,pair <int,int> loction ) {

for (int i = 0; i < board.size(); i++)
{
 for (int j = 0; j <board[0].size(); j++){

 if( Paramedic* f = dynamic_cast<Paramedic*>(board[i][j]) ) {
     if( board[i][j]->team == board[loction.first][loction.second]->team)    
               {
              f->attack(board,{i,j});
                }

}
          }
       }
   }
