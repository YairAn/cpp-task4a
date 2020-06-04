#include <iostream>
#include "DemoGame.hpp"  

using namespace std;

int main() {

	WarGame::DemoGame demoGame;
  
	cout << "The winner is:\n " << demoGame.play() << endl;
    return 0;
}