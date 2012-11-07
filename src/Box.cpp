//
//  Box.cpp
//  intro_3d
//
//  Created by Ira on 10/30/12.
//
//

#include "Box.h"

Box::Box()
{
    
}

Box::Box(const ofVec3f& loc, const ofVec3f& rot, const Dimension3D& dim, const Color4f& color, float mass):
BaseGeom(loc, rot, dim, color), mass(mass)  {
    this->mass = mass;
    init();
}


void Box::calcVerts()
{
    // 8 unique verts
    // top
    verts.push_back(ofVec3f(-.5, .5, .5));
    verts.push_back(ofVec3f(.5, .5, .5));
    verts.push_back(ofVec3f(.5, .5, -.5));
    verts.push_back(ofVec3f(-.5, .5, -.5));
    
    // bottom
    verts.push_back(ofVec3f(-.5, -.5, .5));
    verts.push_back(ofVec3f(-.5, -.5, -.5));
    verts.push_back(ofVec3f(.5, -.5, -.5));
    verts.push_back(ofVec3f(.5, -.5, .5));
    
    for(int i=0; i<verts.size(); i++){
       // verts.at(i)+=ofRandom(-.2, .2);
    }
}


void Box::calcInds()
// 12 tri faces
{
    // front
    indices.push_back(Tuple3i(0, 4, 7));
    indices.push_back(Tuple3i(7, 1, 0));
    // rt
    indices.push_back(Tuple3i(1, 7, 6));
    indices.push_back(Tuple3i(1, 6, 2));
    //back
    indices.push_back(Tuple3i(2, 6, 3));
    indices.push_back(Tuple3i(3, 6, 5));
    // lft
    indices.push_back(Tuple3i(3, 5, 0));
    indices.push_back(Tuple3i(0, 5, 4));
    // top
    indices.push_back(Tuple3i(3, 0, 1));
    indices.push_back(Tuple3i(1, 2, 3));
    // bot
    indices.push_back(Tuple3i(4, 5, 7));
    indices.push_back(Tuple3i(5, 6, 7));

}










