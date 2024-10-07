#include <gol.h>

GameOfLife::GameOfLife(std::vector<std::vector<int>>& seed, int populationSize, Grid* grid) {
    this->populationSize = populationSize;

    this->currentPopulation.resize(populationSize, std::vector<Quad>(populationSize));
    this->nextPopulation.resize(populationSize, std::vector<Quad>(populationSize));

    float offsetX = grid->getOffsetX();
    float offsetY = grid->getOffsetY();
    float cellwidth = grid->getCellWidth();

    for (int y = 0; y < populationSize; y++) {
        for (int x = 0; x < populationSize; x++) {
            this->currentPopulation[x][y] = Quad(x, y, offsetX, offsetY, cellwidth);
            this->currentPopulation[x][y].setLifeState(seed[x][y]);
        }
    }
    nextPopulation = currentPopulation;
}

void GameOfLife::updatePopulation() {
    for (int y = 0; y < this->populationSize; y++) {
        for (int x = 0; x < this->populationSize; x++) {
            this->nextPopulation[x][y].setLifeState(0);
            int aliveNeighbours = 0;
            for (int i = -1; i < 2; i++) {
                for (int j = -1; j < 2; j++) {
                    if (i == 0 && j == 0) continue;
                    int ix = (x+i) % populationSize;
                    int iy = (y+j) % populationSize;
                    if (ix < 0) ix += populationSize;
                    if (iy < 0) iy += populationSize;
                    if (this->currentPopulation[ix][iy].getLifeState() == 1) aliveNeighbours++;
                }
            }
            if (this->currentPopulation[x][y].getLifeState() == 1) {
                if (aliveNeighbours < 2 || aliveNeighbours > 3) {
                    this->nextPopulation[x][y].setLifeState(0);
                }
                else this->nextPopulation[x][y].setLifeState(1);
            } 
            else {
                if (aliveNeighbours == 3) {
                    this->nextPopulation[x][y].setLifeState(1);
                }
            }
        }
    }
    this->currentPopulation = this->nextPopulation;
}

void GameOfLife::renderPopulation() {
    for (int y = 0; y < this->populationSize; y++) {
        for (int x = 0; x < this->populationSize; x++) {
            if (this->currentPopulation[x][y].getLifeState() == 1) {
                this->currentPopulation[x][y].draw();
            }
        }
    }
}