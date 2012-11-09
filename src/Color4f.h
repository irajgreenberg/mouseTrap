//
//  Color4f.h
//  intro_3d
//
//  Created by Ira on 11/6/12.
//
//

#ifndef intro_3d_Color4f_h
#define intro_3d_Color4f_h

#include <iostream>

class Color4f{
public:
    friend std::ostream& operator<<(std::ostream& output, const Color4f& color);
    
    float r, g, b, a;
    Color4f(float r = .5, float g = .5, float b = .5, float a = .5);
    
};

#endif
