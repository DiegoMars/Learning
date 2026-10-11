#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "shaders.h"
#include <iostream>
using namespace std;

// Pretty self-explanatory
void processInput(GLFWwindow* window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

// For redefining the viewport when the window gets resized
void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}

int main() {
    // ---              ---
    // --- Window Stuff ---
    // ---              ---
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    // glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // This is for MAC

    // Width, height, name of window, ignoring the last 2
    GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
    if (window == NULL) {
        cout << "Failed to create GLFW window" << endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    // Initializes GLAD
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        cout << "Failed to initialize GLAD" << endl;
        return -1;
    }

    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // ---                  ---
    // --- Shader Compiling ---
    // ---                  ---
    Shader shader("shaders/vertexShader.vsh", "shaders/fragmentShader.fsh");

    // ---                           ---
    // --- Vertex Array Object Stuff ---
    // ---                           ---
    unsigned int VAO;
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    // ---                       ---
    // --- Triangle Vertex Stuff ---
    // ---                       ---
    float vertices[] = {
        // positions         // colors
         0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,   // bottom right
        -0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,   // bottom left
         0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f    // top 
    };
    unsigned int VBO; // Or virtual buffer object
    glGenBuffers(1, &VBO); // Generates buffers with an ID
    // Mentions how buffers can be binded at once, as long as each as a different type
    glBindBuffer(GL_ARRAY_BUFFER, VBO); // Array buffer is for vertex buffers
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // ---                                      ---
    // --- Linking Vertex Data to Shaders Stuff ---
    // ---                                      ---
    // for positions
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // for colors
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    // ---           ---
    // --- Main Loop ---
    // ---           ---
    while (!glfwWindowShouldClose(window)) {
        processInput(window);

        // Assignment Code
        double timeValue = glfwGetTime();
        float changingValue = (sin(timeValue) / 2.0f) + 0.5f;
        vertices[3] = changingValue;
        vertices[10] = changingValue;
        vertices[17] = changingValue;
        // need to rewrite the vertices to the VBO
        glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices);

        // --                    -- 
        // -- Rendering Commands -- 
        // --                    -- 
        // clears the buffer
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f); // Specifies color to clear the screen
        glClear(GL_COLOR_BUFFER_BIT);
        shader.use();

        // Draws the object
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // Cleans up all resources and properly exits the application
	glfwTerminate();
    return 0;
}
