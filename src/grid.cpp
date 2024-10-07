#include <grid.h>

Grid::Grid(int size) {
    this->size = size;
    this->cellwidth = 1.8f / (float)size;
    GLfloat vertices[(size+1)*6*2];
    GLuint indices[(size+1)*2*2];    

    float originX = -1.0f + offsetX;
    float originY = 1.0f - offsetY;

    for (int i = 0; i < size + 1; i++) {
        vertices[i*6] = originX + i * cellwidth;
        vertices[i*6+1] = originY;
        vertices[i*6+2] = 0.0f;

        vertices[i*6+3] = originX + i * cellwidth;
        vertices[i*6+4] = -originY;
        vertices[i*6+5] = 0.0f;

        indices[i*2] = i*2;
        indices[i*2+1] = i*2+1;
    }

    for (int j = 0; j < size + 1; j++) {
        vertices[(size+1)*6 + j*6] = -originX;
        vertices[(size+1)*6 + j*6+1] = originY - j * cellwidth;
        vertices[(size+1)*6 + j*6+2] = 0.0f;

        vertices[(size+1)*6 + j*6+3] = originX;
        vertices[(size+1)*6 + j*6+4] = originY - j * cellwidth;
        vertices[(size+1)*6 + j*6+5] = 0.0f;

        indices[(size+1)*2 + j*2] = (size+1)*2 + j*2;
        indices[(size+1)*2 + j*2+1] = (size+1)*2 + j*2+1;
    }

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    gridShader = new Shader("../assets/shaders/vertexShaders/grid.vert", "../assets/shaders/fragmentShaders/grid.frag");
  
}

void Grid::drawGrid() const {
    gridShader->Use();
    glBindVertexArray(VAO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glDrawElements(GL_LINES, (size+1)*2*2, GL_UNSIGNED_INT, 0);
        
}

float Grid::getOffsetX() const {
    return offsetX;
}

float Grid::getOffsetY() const {
    return offsetY;
}

float Grid::getCellWidth() const {
    return cellwidth;
}