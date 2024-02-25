//
// Created by William on 2024-02-09.
//

#include "ActeurManager.h"


void ActeurManager::setup(int rows, int cols, char** grid, std::vector<std::shared_ptr<Acteur>>* acteurs)
{

    std::cout << "ActeurManager setup" << std::endl;


    std::cout << "ActeurManager setup" << std::endl;

    for (int i = 0; i < 7; ++i) {
        // Création des 7 robots
        Acteur* nouvel_acteur = new Robot(i);
        acteurs->push_back(std::shared_ptr<Acteur>(nouvel_acteur));
    }
    std::cout << "Robots cree" << std::endl;

    // Création d'un joueur
    Acteur* nouvel_acteur = new Player(7);
    acteurs->push_back(std::shared_ptr<Acteur>(nouvel_acteur));

    std::cout << "Joueur cree" << std::endl;


    for (size_t i = 0; i < acteurs->size(); ++i) {
        acteurs->at(i)->setup(rows,cols,grid) ;
        std::cout << acteurs->at(i)->getId() << std::endl;

    }
    std::cout << "Joueur setup" << std::endl;
}

void ActeurManager::update(char **grid, std::vector<std::shared_ptr<Acteur>>* acteurs)
{
    std::cout << "ActeurManager update" << std::endl;
    for (size_t i = 0; i < acteurs->size(); ++i) {
        acteurs->at(i)->update(grid) ;
        std::cout << acteurs->at(i)->getId() << std::endl;

    }
    std::cout << "Joueur update" << std::endl;

}