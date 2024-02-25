//
// Created by William on 2024-02-09.
//

#ifndef PROJET_S4_MAPMANAGER_H
#define PROJET_S4_MAPMANAGER_H
#include "../Manager.h"
#include <fstream>


class MapManager : public Manager{
    int Rows;
    int Cols;

    char** map;

    void setup(int rows, int cols, char** grid, std::vector<std::shared_ptr<Acteur>>* acteurs) override;
    void update(char **grid, std::vector<std::shared_ptr<Acteur>>* acteurs) override;

};


#endif //PROJET_S4_MAPMANAGER_H
