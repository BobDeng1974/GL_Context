//
//  Quad.hpp
//  Bobo
//
//  Created by Jas S on 2017-02-04.
//  Copyright © 2017 Jas S. All rights reserved.
//

#ifndef Quad_hpp
#define Quad_hpp

#include <stdio.h>

#include "GL.h"

class Quad
{
private:
    static const float DATA[12];
    static GLuint VAO;
    static GLuint VBO;
    
public:
    static inline GLuint getVBO() { return Quad::VBO; }
    static void initalize();
    static void bind();
    static void destroy();
};

#endif /* Quad_hpp */
