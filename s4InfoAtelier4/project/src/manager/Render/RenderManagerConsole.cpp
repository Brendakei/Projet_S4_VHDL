//
// Created by William on 2024-02-09.
//

#include "RenderManagerConsole.h"

void RenderManagerConsole::setup(int Rows, int Cols, char** grid, std::vector<std::shared_ptr<Acteur>>* acteurs)
{
    std::cout << "RenderManagerConsole setup" << std::endl;
    rows = Rows;
    cols = Cols;
}

void RenderManagerConsole::update(char **grid, std::vector<std::shared_ptr<Acteur>>* acteurs)
{

    std::cout << "RenderManagerConsole update" << std::endl;

    // Créer une copie temporaire de la grille
    char** tempGrid = new char*[rows];
    for (int i = 0; i < rows; ++i) {
        tempGrid[i] = new char[cols];
        for (int j = 0; j < cols; ++j) {
            tempGrid[i][j] = grid[i][j];
        }
    }

    // Parcourir tous les acteurs pour arrondir leurs positions et les placer dans la grille temporaire
    for (size_t i = 0; i < acteurs->size(); ++i) {
        int posX = static_cast<int>(std::round(acteurs->at(i)->getposX()));
        int posY = static_cast<int>(std::round(acteurs->at(i)->getposY()));

        // Vérifier si la position est dans les limites de la grille
        if (posX >= 0 && posX < rows && posY >= 0 && posY < cols) {
            tempGrid[posX][posY] = 'A';
        }
    }

    // Imprimer la grille temporaire
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << tempGrid[i][j] << " ";
        }
        std::cout << std::endl;
    }

    // Libérer la mémoire de la grille temporaire
    for (int i = 0; i < rows; ++i) {
        delete[] tempGrid[i];
    }
    delete[] tempGrid;

    std::cout << "avant print acteur" << std::endl;
    for (size_t i = 0; i < acteurs->size(); ++i) {
        std::cout << "acteur : "<< acteurs->at(i)->getId() << " pos x : "<<acteurs->at(i)->getposX()<< " pos Y : " << acteurs->at(i)->getposY()<<std::endl;
        // Accéder à l'élément vecteur[i]
    }



}