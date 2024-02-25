//
// Created by William on 2024-02-09.
//

#ifndef PROJET_S4_ACTEURMANAGER_H
#define PROJET_S4_ACTEURMANAGER_H
#include "../Manager.h"
#include "Player.h"
#include "Robot.h"

class ActeurManager : public Manager{

void setup(int rows, int cols, char** grid, std::vector<std::shared_ptr<Acteur>>* acteurs) override;
void update(char **grid, std::vector<std::shared_ptr<Acteur>>* acteurs) override;

};


#endif //PROJET_S4_ACTEURMANAGER_H
