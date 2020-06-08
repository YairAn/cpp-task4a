#pragma once
#include <vector>
#include <stdexcept>
#include<cmath>
#include<iostream>

#define MAX_VAL 9999999
using namespace std;

#include "FootSoldier.hpp"
using namespace WarGame ;


double distance (int x1, int y1, int x2, int y2  )
{
double  ans = sqrt(pow((x1-x2),2) + pow(y1-y2,2));
return ans;
}

  pair<int,int> FootSoldier::CloserSoldier(std::vector<std::vector<Soldier*>>& board,pair <int,int> loction ) {
    pair<int,int> target ;
    double d = MAX_VAL;
for (int i = 0; i < board.size(); i++)
{
 for (int j = 0; j <board[0].size(); j++){
    if(board[i][j] != nullptr  &&
       board[i][j]->team != board[loction.first][loction.second]->team)   
       {
       
         double t = distance(loction.first,loction.second,i,j);
        if (t < d){
            d=t; 
        target.first = i;
        target.second = j;
      }
    }
   }
}
//Soldier& ans= *target;
if (d == MAX_VAL) {
  target.first = -1;
  target.second = -1; } 
return target;
}

void FootSoldier::attack( std::vector<std::vector<Soldier*>>& board ,pair <int,int> loction ){

pair<int,int> target  = CloserSoldier(board , loction) ;
int x = target.first;
int y = target.second;
if (x== -1 && y == -1) return;
board[x][y]->health -= this->damage; 
if(board[x][y]->health <= 0){
 // cout<<"head shoot"<<endl;
   delete board[x][y];
   board[x][y] = nullptr;
  }

}

  void FootSoldier::fullAttack (std::vector<std::vector<Soldier*>>& board,pair <int,int> loction)
  {

  attack(board,loction);
}