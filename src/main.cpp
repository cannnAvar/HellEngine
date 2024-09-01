#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <math.h>


const char *vertexShaderSource = 
    "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "void main()\n"
    "{\n"
    "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
    "}\0";

const char *fragmentShaderSource = 
    "#version 330 core\n"
    "out vec4 FragColor;\n"
    "void main()\n"
    "{\n"
    "   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
    "}\n\0";

int main()
{
    // Initialize GLFW
    glfwInit();
    // Tell GLFW what openGL version to use
    // This case we are using OPENGL 3.3
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    // Tell GLFW we were using the CORE profile
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


    // Creating window object And define options 
    GLFWwindow* window = glfwCreateWindow(800, 600, "Kurban", NULL, NULL);
    

    // Error Check if the window fails to create give error
    // its really HELPED
    if (window == NULL)
    {
        std::cout << "Failed to create window!" << std::endl;
        glfwTerminate();
        return -1;
    }

    // Introduce window to GLFW for make it understand which window should apair
    glfwMakeContextCurrent(window);
    
    // GLADly load gl
    gladLoadGL();

    // Specify the viewport of OpenGl in the window
    // in this case the viewport goes to x = 0, y = 0, to width = 800, height = 600
    glViewport(0, 0, 800, 600);


    // TODO: Do separate folder file for shaders
    // Create a Vertex shader
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    // Attach Vertex Shader to Vertex shader Source
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    // Compiling vertex shader into macine code 
    glCompileShader(vertexShader);

    // Same Shit above but for fragment shaders
    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);

    // Create Shader Program to link all shaders
    GLuint shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    // Delete Shader because we don't use them
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);


    // The Triangle's vertices with fancy math
    // GLfloat is basicly 
    GLfloat vertices[] = 
    {
        -0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f,
        0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f,
        0.0f, 0.5f * float(sqrt(3)) * 2 / 3, 0.0f,
    };


    // --------------
    // BullShit
    // --------------

    // Warning this part of codes line sequance is important

    // define Vartex Array Object and Vartex Buffer Object
    // not video It's Vartex
    GLuint VAO, VBO;

	// Generate the VAO and VBO with only 1 object each
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    // Bind the VAO 
    glBindVertexArray(VAO);
    // Bind the VBO targets to GL_ARRAT_BUFFER
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    // Introduce the vertices into VBO
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	// Configure the Vertex Attribute so that OpenGL knows how to read the VBO
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    // Enable the Vertex Attribute so that OpenGL knows to use it
    glEnableVertexAttribArray(0);
    
    // Bind both the VBO and VAO to 0 so that we don't accidentally modify the VAO and VBO we created
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    // Run until she (GLFW) you tell you window to close
    while (!glfwWindowShouldClose(window))
    {
        // Give it good colors
        // RGBA, Red Green Blue and ALPHA
        glClearColor(0.07, 0.13f, 0.17f, 1.0f);
        // Clean the back buffer assign the new color to it
        glClear(GL_COLOR_BUFFER_BIT);

        // TODO: Commenting
        glUseProgram(shaderProgram);
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        // WICHcraft (she swaps front buffer and back buffers)
        glfwSwapBuffers(window);
        // She Look for events 
        // This make window response
        glfwPollEvents();
    }

    // Delete VBO, VAO and shader program cus We don't use after program off
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteProgram(shaderProgram);

    glfwDestroyWindow(window);   
    // Burn The Wich (GLFW Terminates her self I don't do anything)
    glfwTerminate();
    return 0;
}
