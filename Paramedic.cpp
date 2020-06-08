#pragma once
#include <vector>
#include <iostream>

#include <stdexcept>
#include<cmath>
#define MAX_VAL 9999999
using namespace std;

#include "Paramedic.hpp"
using namespace WarGame ;


  std::vector <Soldier*> Paramedic::FindFriends(std::vector<std::vector<Soldier*>>& board,pair <int,int> loction ) {
  std::vector <Soldier*> targets;
    int  n = loction.first;
    int m = loction.second;

    for ( int i = n-1; i <= n+1; i++)
    {
        for ( int j = m-1; j <= m+1; j++){

            if(i<0 || i>board.size() -1 || j<0 || j> board.size()-1 || board[i][j]==nullptr){

                continue;
            }
            else{
                if(board[i][j]->team == board[n][m]->team)

                targets.push_back(board[i][j]);
            }
        }
    }
    
return targets;
}

void Paramedic ::attack( std::vector<std::vector<Soldier*>>& board ,pair <int,int> loction ){

std::vector <Soldier*> targets  = FindFriends(board , loction) ;

for (int i=0;i<targets.size();i++){
targets[i]->health=targets[i]->life;
     } 
  }


  void Paramedic::fullAttack (std::vector<std::vector<Soldier*>>& board,pair <int,int> loction)
  {

  attack(board,loction);
}

//}