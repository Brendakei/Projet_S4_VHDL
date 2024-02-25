//
// Created by William on 2024-02-09.
//

#ifndef PROJET_S4_RENDERMANAGERCONSOLE_H
#define PROJET_S4_RENDERMANAGERCONSOLE_H
#include "../Manager.h"


class RenderManagerConsole : public Manager {
    int rows;
    int cols;

    void setup(int rows, int cols, char** grid, std::vector<std::shared_ptr<Acteur>>* acteurs) override;
    void update(char **grid, std::vector<std::shared_ptr<Acteur>>* acteurs) override;

};


#endif //PROJET_S4_RENDERMANAGERCONSOLE_H
