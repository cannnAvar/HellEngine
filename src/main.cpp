#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

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
    GLFWwindow* window = glfwCreateWindow(800, 600, "Mor saclı icin", NULL, NULL);
    
    // Error Check if the window fails to create give error
    // its really HELPED
    if (window == NULL)
    {
        std::cout << "Failed to create window!" << std::endl;
        glfwTerminate();
        return -1;
    }

    // Introduce window to GLFW for make her understand which window should apair
    glfwMakeContextCurrent(window);
    
    // GLADly load gl
    gladLoadGL();

    // Specify the viewport of OpenGl in the window
    // in this case the viewport goes to x = 0, y = 0, to width = 800, height = 600
    glViewport(0, 0, 800, 600);

    // Give it good colors
    // RGBA, Red Green Blue and ALPHA Male
    glClearColor(0.17f, 0.0f, 0.18f, 1.0f);
    // Clean the back buffer assign the new color to it
    glClear(GL_COLOR_BUFFER_BIT);
    // WICHcraft (she swaps front buffer and back buffers)
    glfwSwapBuffers(window);

    // Run until she (GLFW) you tell you window to close
    while (!glfwWindowShouldClose(window))
    {
        // She Look for events 
        // This make window response
        glfwPollEvents();
    }
    
    // Burn The Wich (GLFW Terminates her self I don't do anything)
    glfwTerminate();
    return 0;
}