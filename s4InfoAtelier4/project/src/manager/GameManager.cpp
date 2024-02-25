//
// Created by William on 2024-02-09.
//

#include "GameManager.h"

GameManager ::GameManager(int Rows, int Cols)
{
    rows =  Rows;
    cols = Cols;
}

void GameManager::setup()
{

    grid = new char*[rows];
    for(int i = 0; i < rows; ++i) {
        grid[i] = new char[cols];
    }

    // Création des instances et ajout au vecteur
    // pour ajouter un manager a la frame ajouter le ici
    managers.push_back(std::shared_ptr<Manager>(new MapManager));
    managers.push_back(std::shared_ptr<Manager>(new ActeurManager));
    managers.push_back(std::shared_ptr<Manager>(new RenderManagerConsole));

    for (const auto& manager : managers) {
        manager->setup(rows, cols, grid, &acteurs); // Supposant que chaque manager implémente cette méthode
    }

}

void GameManager::game()
{
    using namespace std::chrono;

    auto frameDuration = milliseconds(1000) / 60; // Durée cible d'une frame à 60 FPS

    while (true) {
        auto frameStart = high_resolution_clock::now();

        // logic start
        for (const auto& manager : managers) {
            manager->update(grid, &acteurs); // Supposant que chaque manager implémente cette méthode
        }
        //logic end

        auto frameEnd = high_resolution_clock::now();
        auto elapsedTime = duration_cast<milliseconds>(frameEnd - frameStart);

        // Si la frame a été traitée plus rapidement que notre cible, attendons le reste du temps.
        if (elapsedTime < frameDuration) {
            std::this_thread::sleep_for(frameDuration - elapsedTime);
        }

        // Optionnel : Calcul et affichage du FPS réel
        //auto actualFrameDuration = duration_cast<milliseconds>(high_resolution_clock::now() - frameStart);
        //std::cout << "Frame Time: " << actualFrameDuration.count() << " ms (" << 1000.0 / actualFrameDuration.count() << " FPS)\n";
    }
}