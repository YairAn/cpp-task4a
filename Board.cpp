
#include <string>
#include <vector>
#include <iostream>

#include <stdexcept>
#include "Board.hpp"

using namespace std;
using namespace WarGame;



// operator for putting soldiers on the game-board during initialization.
    Soldier*& Board::operator[](std::pair<int,int> location){
       
			return this->board[location.first][location.second];

    }
        
    // operator for reading which soldiers are on the game-board.
    Soldier* Board::operator[](std::pair<int,int> location) const{

int r = location.first, c = location.second;
        if (r >= board.size() || r < 0 || c >= board[0].size() || c < 0 )
        {
            throw std::invalid_argument("player is out of bound");
        }
        
        return this->board[location.first][location.second];
    }

    void Board::move(uint player_number, std::pair<int,int> source, Board::MoveDIR direction){

       if ( source.first <0 || 
       source.first>= board.size() || 
       source.second <0 || 
       source.second >= board[0].size() ) 
         throw("player cant move  to that loction_ out of bounds");
       
       


       if ( board[source.first][source.second] ==  nullptr )
              throw("player cant choose that loction_____null ptr");

         if(  board[source.first][source.second]->team != player_number) 
{
              throw("player cant choose that loction_____worng team");

}

       std::pair<int,int> Newloction ; 
       switch (direction)
       {
       case  Up:
         Newloction.first  =  source.first+1;
         Newloction.second = source.second   ;
          break;

       case  Down:
          Newloction.first =  source.first-1;
         Newloction.second = source.second  ;
          break;

       case  Left:
          Newloction.first =  source.first;
         Newloction.second = source.second-1  ;
                      break;

       case  Right:
       Newloction.first =  source.first;
         Newloction.second = source.second+1  ;
          break;
       }

  if ( Newloction.first <0 || 
       Newloction.first>= board.size() || 
       Newloction.second <0 || 
       Newloction.second >= board[0].size() ) 
         throw("player cant move  to that loction");

if (board[Newloction.first][Newloction.second] != nullptr)
         throw("player cant move  to that loction");

    
     board[Newloction.first][Newloction.second] = board[source.first][source.second];
     board[source.first][source.second] = nullptr ;
     board[Newloction.first][Newloction.second]->fullAttack(board , Newloction);
             //cout<< board[Newloction.first][Newloction.second]->team<<" done  attack111"<<endl;

       }
       
       
   
    bool Board::has_soldiers(uint player_number) const {
 
        for(int i=0;i < board.size();i++)
        {
         for(int j=0 ; j < board[0].size();j++){
        
        if ( board[i][j]!=nullptr && board[i][j]->team == player_number)   return true;

        }}
  return false;
     }
    //
    
    
