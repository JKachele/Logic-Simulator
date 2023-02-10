/*File----------main.cpp
 *Author--------Justin Kachele
 *Date----------02/09/2023
 *License-------Mozilla Public License Version 2.0
 *************************************************/
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

int main() {
    // initialize glfw
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Create a glfw window, if fails, exit program
    GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
    if (window == NULL) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    // Initialize GLAD
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    // Set the viewport size and callback to adjust size
    glViewport(0, 0, 800, 600);
    glfwSetFramebufferSizeCallback(window,
                                [](GLFWwindow* window, int width, int height) {
        glViewport(0, 0, width, height);
    });

    // Main rendering loop
    while (!glfwWindowShouldClose(window)) {
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
