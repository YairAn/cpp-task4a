
#include <vector>
#include <stdexcept>
#include "Paramedic.hpp"
using namespace std;
using namespace WarGame;

class ParamedicCommander  : public Paramedic{
    public: 
ParamedicCommander() {}
~ParamedicCommander() {}
ParamedicCommander(int t) {
 const int health=200;  
 life=200;
 team =t;
}

void fullAttack(std::vector<std::vector<Soldier*>>& board ,pair <int,int> loction)override ;
void attack(std::vector<std::vector<Soldier*>>& board ,pair <int,int> loction) ;
};

