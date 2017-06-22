//
//  Quad.cpp
//  Bobo
//
//  Created by Jas S on 2017-02-04.
//  Copyright © 2017 Jas S. All rights reserved.
//

#include "Quad.h"

const float Quad::DATA[12] =
{
    // top triangle
    1.0f,  1.0f, // top right
    -1.0f,  1.0f, // top left
    -1.0f, -1.0f, // bottom left
    // bottom triangle:
    1.0f,  1.0f, // top right
    -1.0f, -1.0f, // bottom left
    1.0f, -1.0f  // bottom right
};

GLuint Quad::VAO = 0;
GLuint Quad::VBO = 0;

void Quad::initalize()
{
    glGenVertexArrays(1, &Quad::VAO);
    glGenBuffers(1, &Quad::VBO);
    
    glBindVertexArray(Quad::VAO);
    glBindBuffer(GL_ARRAY_BUFFER, Quad::VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Quad::DATA), Quad::DATA, GL_STATIC_DRAW);
    
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, (void*) 0);
    
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

void Quad::bind()
{
    glBindVertexArray(Quad::VAO);
}

void Quad::destroy()
{
    if(glIsBuffer(Quad::VBO) == GL_TRUE) glDeleteBuffers(1, &Quad::VBO);
    if(glIsVertexArray(Quad::VAO) == GL_TRUE) glDeleteVertexArrays(1, &Quad::VAO);
}
