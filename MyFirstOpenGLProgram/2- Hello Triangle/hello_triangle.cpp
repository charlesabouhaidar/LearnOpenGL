//
//  hello_triangle.cpp
//  MyFirstOpenGLProgram
//
//  Created by Charles on 2021-01-16.
//

#include <stdio.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>


int main(){
    
    // vertex shader source code (page 30)
    const char *vertexShaderSourceCode = "#version 330 core\m"
        "layout (location = 0) in vec3 aPos;\n"
        "void main(){\n"
        "gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);"
    "}\0";
    
    float vertices[] = {
        -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        0.0f, 0.5f, 0.0f
    };
    
    // generate VBO with a buffer ID
    unsigned int VBO;
    glGenBuffers(1, &VBO);
    
    // bind the newly created buffer to GL_ARRAY_BUFFER target
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    
    //copy previously defined verted data into buffer's memory
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    
    
    return 0;
}

