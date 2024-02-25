//
// Created by William on 2024-02-09.
//

#ifndef PROJET_S4_GAMEMANAGER_H
#define PROJET_S4_GAMEMANAGER_H


#include <vector>
#include <memory>
#include <chrono>
#include <thread>

#include "Manager.h"
#include "Map/MapManager.h"
#include "Acteur/ActeurManager.h"
#include "Render/RenderManagerConsole.h"

#include "Acteur/Acteur.h"

class GameManager {
private:
    char** grid;
    int rows, cols;
    Manager* firstManager; // Premier manager dans la chaîne

    std::vector<std::shared_ptr<Manager>> managers;
    std::vector<std::shared_ptr<Acteur>> acteurs;


public:
    GameManager(int rows, int cols);
    ~GameManager();




    void setup(); // Configuration initiale du jeu
    void game(); // Exécution principale du jeu
};


#endif //PROJET_S4_GAMEMANAGER_H
