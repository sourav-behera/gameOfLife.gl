#ifndef QUAD_H
#define QUAD_H

#include <glad/glad.h>
#include <shader.h>
#include <stdlib.h>
#include <grid.h>

class Quad {
    private:
        bool alive = false;
        int x, y;
        uint VAO, VBO, EBO;
        Shader* quadShader;

    public:
        Quad(int x, int y, float offsetX, float offsetY, float cellwidth);
        void Draw() const;
};

#endif