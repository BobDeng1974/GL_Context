//
//  Framebuffer.hpp
//  RoughRocket
//
//  Created by Jas S on 2017-05-04.
//  Copyright © 2017 Jas S. All rights reserved.
//

#ifndef Framebuffer_hpp
#define Framebuffer_hpp

#include <stdio.h>

#include "GL.h"
#include "Math3d.h"
#include "Attachment.h"

class FBO // general purpose framebuffer
{
protected:
    GLuint id;
    glm::uvec2 dimensions;
    
	void init(unsigned int width, unsigned int height);
	void check(unsigned int attachments);
	void destroy();

public:
    FBO(){}
    
    inline void bind() const {
        glBindFramebuffer(GL_FRAMEBUFFER, this->id);
        glViewport(0, 0, this->dimensions.x, this->dimensions.y);
    }
    
    inline void unbind() const {
        glBindFramebuffer(GL_FRAMEBUFFER, 0);
        glViewport(0, 0, this->dimensions.x, this->dimensions.y);
    }
    
    inline const glm::uvec2& getDimensions() const { return this->dimensions; }
};

class Framebuffer : public FBO // regular framebuffer with a color and depth texture
{
private:
	GLuint texture_attachment;
	GLuint depth_attachment;

public:
	Framebuffer() {}
    Framebuffer(unsigned int width, unsigned int height, Attachment::Type texture_type, Attachment::Type depth_type){ this->initalize(width, height, texture_type, depth_type); }
	void initalize(unsigned int width, unsigned int height, Attachment::Type texture_type, Attachment::Type depth_type);
	void destroy();
    
    inline GLuint getTextureAttachment() const { return this->texture_attachment; }
    inline GLuint getDepthAttachment() const { return this->depth_attachment; }
};

#endif /* Framebuffer_hpp */
