#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <vector>
#include <shader.h>
#include <grid.h>
#include <quad.h>
#include <unistd.h>
#include <gol.h>

// Window Specific
int window_Width = 800;
int window_Height = 800;

// Game of Life Specific
const int GRID_SIZE = 70;

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
    window_Width = width;
    window_Height = height;
}

int main() {

    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(window_Width, window_Height, "opengl", nullptr, nullptr);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glfwMakeContextCurrent(window);

    gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

    Shader quadShader("../assets/shaders/vertexShaders/quad.vert", "../assets/shaders/fragmentShaders/quad.frag");


    Grid grid(GRID_SIZE);

    std::vector<std::vector<int>> seed(GRID_SIZE, std::vector<int>(GRID_SIZE));


    seed[10][10] = 1, seed[10][11] = 1, seed[10][12] = 1;
    seed[9][11] = 1, seed[11][12] = 1;

    GameOfLife gol(seed, GRID_SIZE, &grid);
    bool start = false;

    while(!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);
        
        //exit
        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
            glfwSetWindowShouldClose(window, true);
        }

        if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS) {
            start = true;
        }
        // render logic
        grid.drawGrid();
        gol.renderPopulation();

        if (start) {
            gol.updatePopulation();
        }
        // refresh
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}