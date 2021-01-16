#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);

int main(){
    
    // initialize GLFW
    glfwInit();
    
    //configure GLFW by telling it to set the major version to 3 and minor to 3 (v3.3)
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    
    //configure GLFW by telling it we want to explicitly use the core profile
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    
    //specifically for Mac OS X
    #ifdef __APPLE__
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    #endif
    
    // CREATING A WINDOW OBJECT
    GLFWwindow* window = glfwCreateWindow(800, 600, "Learn OpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    //make context of our window the main context on the current thread
    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }
        
    void framebuffer_size_callback(GLFWwindow* window, int wiedth, int height);
    
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    
    // checks at start of each loop if GLFW has been instructed to close
    while(!glfwWindowShouldClose(window)){
        
        //without this line I'd get a flashing red window on Mac OS X
        glClear(GL_COLOR_BUFFER_BIT);
        
        // swap color buffer (large 2d buffer containing color values for each pixel in GLFW's window) used to output to the screen
        glfwSwapBuffers(window);
        
        //checks if any events are triggered to then call corresponding functions
        glfwPollEvents();
    }
    glfwTerminate();
    return 0;
}

// resize when user changes size of window
void framebuffer_size_callback(GLFWwindow* window, int width, int height){
    glViewport(0, 0, width, height);
}


