//
// Created by William on 2024-02-09.
//

#ifndef PROJET_S4_MANAGER_H
#define PROJET_S4_MANAGER_H

#include <iostream>
#include "Acteur/Acteur.h"

#include <vector>
#include <memory>
#include <cmath>


class Manager {
public:
    // Méthode update virtuelle pure, à implémenter par les sous-classes
    virtual void setup(int rows, int cols, char** grid, std::vector<std::shared_ptr<Acteur>>* acteurs) = 0;
    virtual void update(char** grid, std::vector<std::shared_ptr<Acteur>>* acteurs) = 0;
};


#endif //PROJET_S4_MANAGER_H
