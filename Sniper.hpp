
#include <vector>
#include <stdexcept>

using namespace std;
//using namespace WarGame;

class Sniper  : public WarGame::Soldier{
    public: 
Sniper(int t) {
 const int health=100;  
 damage=50;
 life=100;
 team =t;
}
//void attack ();
};

