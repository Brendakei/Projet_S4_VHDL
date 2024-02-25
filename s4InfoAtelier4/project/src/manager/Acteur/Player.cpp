//
// Created by willi on 2024-02-15.
//

#include "Player.h"



void Player::setup(int rows, int cols,char** grid)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> rowDist(2, rows - 2);
    std::uniform_int_distribution<> colDist(2, cols - 2);

    int PosX, PosY;
    do {
        PosX = rowDist(gen);
        PosY = colDist(gen);
        // Vérifie que PosX et PosY sont dans les limites de la grille
        if (PosX < 0 || PosX >= rows || PosY < 0 || PosY >= cols) {
            std::cerr << "Erreur : Position en dehors des limites de la grille." << std::endl;
            return; // Sort de la fonction si la position est invalide
        }
    } while (grid[PosX][PosY] == '#'); // Vérifie si la case est occupée


    // Mettre à jour les positions de l'acteur
    posX = PosX;
    posY = PosY;
}
void Player::update(char** grid) { // need to be change -------------------------------------------------------------------------------------------------

    // Copie de la position actuelle
    float currentPosX = posX;
    float currentPosY = posY;

    // Déterminer la direction actuelle
    Direction currentDirection = lasDirection;

    // Déterminer les déplacements possibles dans les quatre directions
    std::vector<Direction> possibleDirections;
    if (grid[static_cast<int>(currentPosX - 0.1)][static_cast<int>(currentPosY)] != '#') possibleDirections.push_back(Direction::Up);
    if (grid[static_cast<int>(currentPosX + 0.1)][static_cast<int>(currentPosY)] != '#') possibleDirections.push_back(Direction::Down);
    if (grid[static_cast<int>(currentPosX)][static_cast<int>(currentPosY - 0.1)] != '#') possibleDirections.push_back(Direction::Left);
    if (grid[static_cast<int>(currentPosX)][static_cast<int>(currentPosY + 0.1)] != '#') possibleDirections.push_back(Direction::Right);

    // Vérifier si la direction précédente est toujours possible
    if (std::find(possibleDirections.begin(), possibleDirections.end(), currentDirection) != possibleDirections.end()) {
        // La direction précédente est possible, donc on la garde
        nextDirection = currentDirection;
    } else {
        // Choisir une nouvelle direction aléatoire parmi les directions possibles
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dist(0, possibleDirections.size() - 1);
        int randomIndex = dist(gen);
        nextDirection = possibleDirections[randomIndex];
    }

    // Mettre à jour la position en fonction de la nouvelle direction
    switch (nextDirection) {
        case Direction::Up:
            posX = currentPosX - 0.1;
            posY = currentPosY;
            break;
        case Direction::Down:
            posX = currentPosX + 0.1;
            posY = currentPosY;
            break;
        case Direction::Left:
            posX = currentPosX;
            posY = currentPosY - 0.1;
            break;
        case Direction::Right:
            posX = currentPosX;
            posY = currentPosY + 0.1;
            break;
        case Direction::None:
            // Ne rien faire si la direction est None
            break;
    }

    // Mettre à jour la dernière direction
    lasDirection = nextDirection;

}