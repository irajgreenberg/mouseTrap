//
//  Icosahedron.cpp
//  intro_3d
//
//  Created by Ira on 11/8/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>


#include "Icosahedron.h"

Icosahedron::Icosahedron()
{
    
}

Icosahedron::Icosahedron(const ofVec3f& loc, const ofVec3f& rot, const Dimension3D& dim, const Color4f& color, float mass):
BaseGeom(loc, rot, dim, color)  {
    init();
}


void Icosahedron::calcVerts()
{
    // 12 unique verts
    float c = ofDist(cos(0), sin(0), cos(PHI), sin(PHI));
    float b = 1.0;
    float a = (float)(sqrt(((c*c)-(b*b))));
    float theta = 0;
    float triHt = (float)(sqrt((c*c)-((c/2)*(c/2))));
    
    verts.push_back(ofVec3f(0, 0, triHt/2.0f+a));
    for (int i=0; i<PENTAGON_ARR_LEN; i++) {
         verts.push_back(ofVec3f(cos(theta), sin(theta), triHt/2.0f));
        theta+=PHI;
    }
    
    theta = PHI/2.0;
    for (int i=0; i<PENTAGON_ARR_LEN; i++) {
         verts.push_back(ofVec3f(cos(theta), sin(theta), -triHt/2.0f));
        theta+=PHI;
    }
     verts.push_back(ofVec3f(0, 0, -(triHt/2.0f+a)));

}


void Icosahedron::calcInds()

{
    // top
    indices.push_back(Tuple3i(0, 1, 2));
    indices.push_back(Tuple3i(0, 2, 3));
    indices.push_back(Tuple3i(0, 3, 4));
    indices.push_back(Tuple3i(0, 4, 5));
    indices.push_back(Tuple3i(0, 5, 1));
    
    // middle
    indices.push_back(Tuple3i(1, 6, 10));
     indices.push_back(Tuple3i(1, 10, 2));
    
    indices.push_back(Tuple3i(2, 10, 9));
    indices.push_back(Tuple3i(2, 9, 3));
    
    // bottom
    indices.push_back(Tuple3i(11, 6, 10));
    indices.push_back(Tuple3i(11, 10, 9));
    indices.push_back(Tuple3i(11, 9, 8));
    indices.push_back(Tuple3i(11, 8, 7));
    indices.push_back(Tuple3i(11, 7, 6));
    
   }
