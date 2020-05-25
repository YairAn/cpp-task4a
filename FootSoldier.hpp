
#include <vector>
#include <stdexcept>

using namespace std;
//using namespace WarGame;

class FootSoldier  : public WarGame::Soldier{
    public: 
FootSoldier(int t) {
 const int health=100;  
 damage=10;
 life=100;
 team = t;
}
//void attack ();
};

