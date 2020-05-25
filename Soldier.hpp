
#include <vector>
#include <stdexcept>
using namespace std;
namespace WarGame {

class Soldier{
    public: 
        int health;
        int damage ;
        int life;
        int team;

Soldier():health(100),life(100),damage(10){}
//virtual void attack ();
};

}