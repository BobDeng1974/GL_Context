//
//  FrameRenderer.hpp
//  RoughRocket
//
//  Created by Jas S on 2017-05-04.
//  Copyright © 2017 Jas S. All rights reserved.
//

#ifndef FrameRenderer_hpp
#define FrameRenderer_hpp

#include <stdio.h>

#include "GL.h"
#include "Math3d.h"
#include "Quad.h"
#include "Shader.h"

class _FrameRenderer : public Shader
{
private:
    GLuint tex;
public:
    _FrameRenderer(){}
    void initalize();
    void render(GLuint texture_id);
    void destroy();
};

extern _FrameRenderer FrameRenderer;

#endif /* FrameRenderer_hpp */
