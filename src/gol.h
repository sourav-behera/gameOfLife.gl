#ifndef GAMEOFLIFE_H
#define GAMEOFLIFE_H

#include <quad.h>
#include <grid.h>
#include <vector>

class GameOfLife{
    private:
        std::vector<std::vector<Quad>> currentPopulation, nextPopulation;
        int populationSize;
    public:
        GameOfLife(std::vector<std::vector<int>>& seed, int populationSize, Grid* grid);
        void updatePopulation ();
        void renderPopulation();
};

#endif