#include <glad/glad.h>
#include <GLFW/glfw3.h>
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

// This is written in GLSL (OpenGL Shading Language)
// Converts 3d points to 2d I think
const char* vertexShaderSource = "#version 330 core\n"
    // Create a vertex for 3d called aPos, into location 0
    "layout (location = 0) in vec3 aPos;\n"
    "void main()\n"
    "{\n"
        // Set output of position data into gl_position
        // as the shader output
    "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
    "}\0";

// Fragment Shader. Calculates color output of pixels
const char* fragmentShaderSource = "#version 330 core\n"
    "out vec4 FragColor;\n"
    "void main()\n"
    "{\n"
        // Defines the color in RGBA
    "   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
    "}\n";

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

    // Tells OpenGL the dimensions of the window
    // These could be smaller than the actual window, for the purposes
    // of rendering outside of the it
    // first 2 parameters are the location of the bottom left corner
    // 3rd and 4th are the width and height
    // glViewport(0, 0, 800, 600); // this is called from the function below too

	// Set the function to be used
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    // All this would also be called when first displayed
    // This is one example of us setting our own functions, and could also be done
    // for joystick inputs, processing error messages, etc

    // ---                  ---
    // --- Shader Compiling ---
    // ---                  ---
    // For a shader to be used, OpenGL needs to compile it at run-time
    // For Vertex Shaders
    unsigned int vertexShader;
    vertexShader = glCreateShader(GL_VERTEX_SHADER); // Creates shader with id
    // shader object, # of strings in source code, actual source code
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL); // Attach code to shader
    glCompileShader(vertexShader); // Compile Shader
    // Check if compile succeeded
    int success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << endl;
    }

    // For Fragment Shaders
    unsigned int fragmentShader;
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);
    // Check if compile succeeded
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << endl;
    }
    
    // Shader Program: Links multiple shaders and used for rendering objects
    // Links the output of one shader into the next. Will throw an error if
    // outputs and inputs don't match
    unsigned int shaderProgram;
    shaderProgram = glCreateProgram(); // Returns id
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);
    // Checking if linking worked
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(shaderProgram, 512, NULL, infoLog);
        cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << endl;
    }
    // Finally, use the program object
    // glUseProgram(shaderProgram); // Called in loop
    // No longer need shader objects after linking
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    // ---                           ---
    // --- Vertex Array Object Stuff ---
    // ---                           ---
    // The VAO (Vertex Array Object) works like the VBO, where and vertex attribute
    // calls are stored inside the VAO.
    unsigned int VAO;
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO); // To save bindings and such

    // ---                       ---
    // --- Triangle Vertex Stuff ---
    // ---                       ---
    // *Normalized Device Coordinates (NDC)*
    // Are transformed to screen-space coordinates via viewport transform
    // These need to be between -1 and 1, then are translated to the window
    // These are 3d points that are translated into 2d
    float vertices[] = {
        -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        0.0f, 0.5f, 0.0f
    };
    unsigned int VBO; // Or virtual buffer object
    glGenBuffers(1, &VBO); // Generates buffers with an ID
    // Mentions how buffers can be binded at once, as long as each as a different type
    glBindBuffer(GL_ARRAY_BUFFER, VBO); // Array buffer is for vertex buffers
    // Any future calls to the array buffer configs the VBO

    // The fourth parameter can be
    // - GL_STREAM_DRAW: Data is only set once and used by the GPU a few times
    // - GL_STATIC_DRAW: Data is only set once and used many times
    // - GL_DYNAMIC_DRAW: Data is changed many times and used many times
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // ---                              ---
    // --- Element Buffer Objects (EBO) ---
    // ---                              ---
    // Didn't include it here, but basically this is where we can take the verticies
    // and specify where vertices to use for drawing. This is so that you can reuse
    // vertices instead of adding multiple of the same vertices. It is binded and
    // configured almost the same as the VBO

    // ---                                      ---
    // --- Linking Vertex Data to Shaders Stuff ---
    // ---                                      ---
    // Parameters of the following
    // - Vertex attribute to configure (remember `layout (location = 0)`,
    // - Size of vertex attribute
    // - Type of data
    // - Specify if we want the data normalized, (for when we input int data)
    // - Stride, telling us the space between consecutive vertex attributes. Could also
    //   be 0 if you want OpenGL to figure it out, but array must be tightly packed
    // - Offest of where the position data begins in the buffer
    // All in all, this tells OpenGL how to interpret vertex data
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // ---           ---
    // --- Main Loop ---
    // ---           ---
    // This is the render loop, meaning the window won't just close after drawing once
    // These are your frames
    while (!glfwWindowShouldClose(window)) {
        processInput(window);

        // --                    -- 
        // -- Rendering Commands -- 
        // --                    -- 
        // clears the buffer
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f); // Specifies color to clear the screen
        glClear(GL_COLOR_BUFFER_BIT);
        // Draws the object
        glUseProgram(shaderProgram);
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3); // draws primitive with current shaders
                                          // primitive, start pos of vertex array,
                                          // end pos of vertex array

        // --                        -- 
        // -- End Rendering Commands -- 
        // --                        -- 

        // Swaps color buffer (2D buffer with color values for every pixel), that is
        // used to render this iteration and output it to the screen
        glfwSwapBuffers(window);
        // *Double Buffers*: One buffer could create artifacts from not being rendered
        // completely when shown, so 2 buffers are used. While one is shown the other
        // is rendered

		// Checks for any triggered events, update window size, and calls functions
        glfwPollEvents();
    }

    // Cleans up all resources and properly exits the application
	glfwTerminate();
    return 0;
}
