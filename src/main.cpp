#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <vector>
#include <shader.h>
#include <grid.h>
#include <quad.h>

int window_Width = 800;
int window_Height = 800;

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

    Grid grid(10, 0.18f);
    Quad quad1(0, 0, 0.1f, 0.1f, 0.18f);
    Quad quad2(1, 1, 0.1f, 0.1f, 0.18f);

    while(!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);
        
        //exit
        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
            glfwSetWindowShouldClose(window, true);
        }

        // render logic

        //grid
        grid.drawGrid();
        quad1.Draw();
        quad2.Draw();

        // refresh
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}