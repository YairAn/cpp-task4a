
#include <string>
#include <vector>
#include <stdexcept>
#include "Board.hpp"

using namespace std;
using namespace WarGame;



// operator for putting soldiers on the game-board during initialization.
    Soldier*& Board::operator[](std::pair<int,int> location){
              return board[location.first][location.second];

    }
        
    // operator for reading which soldiers are on the game-board.
    Soldier* Board::operator[](std::pair<int,int> location) const{
       return board[location.first][location.second];

    }

    void Board::move(uint player_number, std::pair<int,int> source, Board::MoveDIR direction){;}
   
    bool Board::has_soldiers(uint player_number) const {
        
        for(int i=0;i<board.size();i++)
        {
         for(int j=0 ; j<board[i].size();j++)

        if ( board[i][j]!=nullptr && board[i][j]->team==player_number)   return true;

        }
  return false;
     }
    //
    
    


