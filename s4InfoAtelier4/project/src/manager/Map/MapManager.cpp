//
// Created by William on 2024-02-09.
//

#include "MapManager.h"

void MapManager::update(char **grid, std::vector<std::shared_ptr<Acteur>>* acteurs)
{
    std::cout << "MapManager update" << std::endl;
    for (int i = 0; i < Rows; ++i) {
        for (int j = 0; j < Cols; ++j) {
            grid[i][j] = map[i][j]; // Copie chaque caractère de map dans grid
        }
    }
}

void MapManager::setup(int rows, int cols, char** grid, std::vector<std::shared_ptr<Acteur>>* acteurs)
{
    Rows = rows;
    Cols = cols;
    std::cout << "MapManager setup" << std::endl;

    // Allocation de la mémoire pour le tableau 2D map
    map = new char*[rows];
    for(int i = 0; i < rows; ++i) {
        map[i] = new char[cols];
    }

    const std::string& filename = "../exemple/labyrinte1";
    // Ouverture du fichier contenant la carte
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Erreur lors de l'ouverture du fichier de carte" << std::endl;
        return;
    }

    std::string line;
    int row = 0;
    // Lecture de chaque ligne du fichier
    while (getline(file, line) && row < rows) {
        for (int col = 0; col < cols && col < line.length(); ++col) {
            map[row][col] = line[col];
        }
        ++row;
    }

    file.close(); // Fermeture du fichier


}