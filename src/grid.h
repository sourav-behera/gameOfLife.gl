#ifndef GRID_H
#define GRID_H

#include "glad/glad.h"
#include "shader.h"
#include <stdlib.h>

class Grid {
    private:
        int size = 10;
        uint VAO, VBO, EBO;
        Shader* gridShader;
    public:
        float cellwidth = 1.8f / (float)size;
        //TODO: change the offset
        float offsetX = 0.1f;
        float offsetY = 0.1f;
        Grid(int size, float cellwidth);
        void drawGrid() const;
};

#endif