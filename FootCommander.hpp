
#include <vector>
#include <stdexcept>

using namespace std;
//using namespace WarGame;

class FootCommander  : public WarGame::Soldier{
    public: 
FootCommander(int t) {
 const int health=150;  
 damage=20;
 life=150;
 team =t;
}
//void attack ();
};

