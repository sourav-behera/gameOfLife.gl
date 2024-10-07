#include <quad.h>

Quad::Quad(){
    this->alive = false;
}

Quad::Quad(int x, int y, float offsetX, float offsetY, float cellWidth) {
    this->x = x;
    this->y = y;
    float originX = -1.0f + offsetX;
    float originY = 1.0f - offsetY;

    GLfloat quadVertices[] = {
        originX + x * cellWidth, originY - y * cellWidth, 0.0f,
        originX + x * cellWidth, originY - (y + 1) * cellWidth, 0.0f,
        originX + (x + 1) * cellWidth, originY - (y + 1) * cellWidth, 0.0f,
        originX + (x + 1) * cellWidth, originY - y * cellWidth, 0.0f,
    };

    GLuint quadIndices[] = {
        0, 1, 2,
        2, 3, 0
    };

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(quadVertices), quadVertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(quadIndices), quadIndices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (void*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    quadShader = new Shader("../assets/shaders/vertexShaders/quad.vert", "../assets/shaders/fragmentShaders/quad.frag");
}

void Quad::draw() const {
    quadShader->Use();
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

bool Quad::getLifeState() const {
    return this->alive;
}

void Quad::setLifeState(bool aliveState) {
    this->alive = aliveState;
}