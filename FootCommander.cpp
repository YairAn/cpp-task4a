//#pragma once
#include <vector>
#include <stdexcept>
#include <iostream>

#include<cmath>
#include<iostream>

#include "FootCommander.hpp"
using namespace std;
using namespace WarGame;

void FootCommander::fullAttack(std::vector<std::vector<Soldier*>>& board ,pair <int,int> loction ) {

for (int i = 0; i < board.size(); i++)
{
 for (int j = 0; j <board[0].size(); j++){
   
                  //cout<<"this is "<< i<<"," <<j<<endl;
                 //cout<<"team is "<< board[loction.first][loction.second]->team<<endl;
 if( FootSoldier* f = dynamic_cast<FootSoldier*>(board[i][j]) ) {
     if( board[i][j]->team == board[loction.first][loction.second]->team)    
               {
                 
                  f->attack(board,{i,j});
                }

}
          }
       }
   }
