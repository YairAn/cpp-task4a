
#include <vector>
#include <stdexcept>

using namespace std;
//using namespace WarGame;

class SniperCommander  : public WarGame::Soldier{
    public: 
SniperCommander(int t) {
 const int health=120;  
 damage=100;
 life=120;
 team =t;
}
//void attack ();
};

