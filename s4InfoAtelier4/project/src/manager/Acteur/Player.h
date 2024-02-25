//
// Created by willi on 2024-02-15.
//

#ifndef PROJET_S4_PLAYER_H
#define PROJET_S4_PLAYER_H

#include "Acteur.h"


class Player: public Acteur{






    public:
    void setup(int rows, int cols,char** grid) override;
    void update(char** grid) override;
    Player(int Id) : Acteur(Id)
    {

    }

};


#endif //PROJET_S4_PLAYER_H
