//
//  FrameRenderer.cpp
//  RoughRocket
//
//  Created by Jas S on 2017-05-04.
//  Copyright © 2017 Jas S. All rights reserved.
//

#include "FrameRenderer.h"

_FrameRenderer FrameRenderer;

void _FrameRenderer::initalize()
{
    ShaderSource source = ShaderSource("/Users/jass/Documents/Libraries/GL_Context/src/Shaders/frame.vert", "/Users/jass/Documents/Libraries/GL_Context/src/Shaders/frame.frag");
    this->source(source);
    this->bindAttributeLocation(0, "vertex");
    this->link(source);
    this->tex = this->getUniform("tex");
}

void _FrameRenderer::render(GLuint texture_id)
{
    this->bind();
    Quad::bind();
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texture_id);
    glUniform1i(this->tex, 0);
    glDrawArrays(GL_TRIANGLES, 0, 6);
    glBindVertexArray(0);
}

void _FrameRenderer::destroy()
{
    Shader::destroy();
}
