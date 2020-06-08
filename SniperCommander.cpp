//#pragma once
#include <vector>
#include <stdexcept>
#include<cmath>
#include "SniperCommander.hpp"
#include <iostream>

using namespace std;
using namespace WarGame;

void SniperCommander::fullAttack(std::vector<std::vector<Soldier*>>& board ,pair <int,int> loction ) {

for (int i = 0; i < board.size(); i++)
{
 for (int j = 0; j < board[0].size(); j++){

 if( Sniper* f = dynamic_cast<Sniper*>(board[i][j]) ) {
     if( board[i][j]->team == board[loction.first][loction.second]->team)    
               {
              f->attack(board,{i,j});
                }

}
          }
       }
   }
