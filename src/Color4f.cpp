//
//  Color4f.cpp
//  intro_3d
//
//  Created by Ira on 11/6/12.
//
//

#include "Color4f.h"

std::ostream& operator<<(std::ostream& output, const Color4f& color)
{
    output << "Color4f color: [ r = "<<color.r<<" g = "<<color.g<<" b = "<<color.b<<" a = "<<color.a<<" ]";
    return output;
}

Color4f::Color4f(float r, float g, float b, float a):
r(r), g(g), b(b), a(a){
    
}