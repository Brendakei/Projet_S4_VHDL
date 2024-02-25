//
// Created by willi on 2024-02-15.
//

#include "Acteur.h"

Acteur::Acteur(int Id)
{
    id =Id;
}

int Acteur::getId()
{
    return id;
}

float Acteur::getposX()
{
    return posX;
}
float  Acteur::getposY()
{
    return posY;
}

