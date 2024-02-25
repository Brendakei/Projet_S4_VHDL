//
// Created by willi on 2024-02-15.
//

#ifndef PROJET_S4_ACTEUR_H
#define PROJET_S4_ACTEUR_H


#include "../../enum/direction.h"
#include <random>
#include <iostream>
#include <algorithm>


class Acteur {


    Acteur();

  protected:
    float posX=0;
    float posY=0;

    int id=0;





    Direction lasDirection = Direction::None;
    Direction nextDirection = Direction::None;

   public:
    Acteur(int id);
    virtual void setup(int rows, int cols,char** grid)=0;
    virtual void update(char** grid)=0;
    int getId();

    float getposX();
    float  getposY();

};


#endif //PROJET_S4_ACTEUR_H
