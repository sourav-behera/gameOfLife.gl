#ifndef GRID_H
#define GRID_H

#include "glad/glad.h"
#include "shader.h"
#include <stdlib.h>

class Grid {
    private:
        int size;
        uint VAO, VBO, EBO;
        Shader* gridShader;

    public:
        float cellwidth;
        float offsetX = 0.1f;
        float offsetY = 0.1f;

    public:
        Grid(int size);
        void drawGrid() const;
        float getCellWidth() const;
        float getOffsetX() const;
        float getOffsetY() const;
};

#endif