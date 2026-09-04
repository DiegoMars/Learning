#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
using namespace std;

// For redefining the viewport when the window gets resized
void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}

// Pretty self-explanatory
void processInput(GLFWwindow* window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

int main() {
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

    // Tells OpenGL the dimensions of the window
    // These could be smaller than the actual window, for the purposes
    // of rendering outside of the it
    // first 2 parameters are the location of the bottom left corner
    // 3rd and 4th are the width and height
    glViewport(0, 0, 800, 600);

	// Set the function to be used
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    // All this would also be called when first displayed
    // This is one example of us setting our own functions, and could also be done
    // for joystick inputs, processing error messages, etc

    // This is the render loop, meaning the window won't just close after drawing once
    // These are your frames
    while (!glfwWindowShouldClose(window)) {
        processInput(window);

        // -- rendering commands here -- 
        // clears the buffer
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f); // Specifies color to clear the screen
        glClear(GL_COLOR_BUFFER_BIT);

        // Swaps color buffer (2D buffer with color values for every pixel), that is
        // used to render this iteration and output it to the screen
        glfwSwapBuffers(window);
        // *Double Buffers*: One buffer could create artifacts from not being rendered
        // completely when shown, so 2 buffers are used. While one is shown the other
        // is rendered

		// Checks for any triggered events, update window size, and calls functions
        glfwPollEvents;
    }

    // Cleans up all resources and properly exits the application
	glfwTerminate();
    return 0;
}
