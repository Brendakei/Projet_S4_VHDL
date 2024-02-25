#include <iostream>
#include "manager/GameManager.h"
int main() {
    std::cout << "start up!" << std::endl;

    GameManager* jeu1 = new GameManager(25, 25);
    jeu1 ->setup();
    jeu1 ->game();

    return 0;
}
