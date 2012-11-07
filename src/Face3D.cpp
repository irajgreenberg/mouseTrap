//
//  Face3D.cpp
//  animatingParticles
//
//  Created by Ira on 8/30/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <Face3D.h>


Face3D::Face3D(const ofVec3f& v0, const ofVec3f& v1, const ofVec3f& v2):
v0(v0), v1(v1), v2(v2){
    
    calcNormal();
    calcCentroid();
}


ofVec3f& Face3D::getNormal()
{
    return normal;
}

// Must be calcualted anytime vertex geometry is transformed.
// transformationa to the Graphics context don't require
// new normal calculation.
void Face3D::calcNormal()
{
    /*
     Face v0, v1, v2
     vector U = v1 - v0
     vector V = v2 - v0
     normal U X V
     Nx = UyVz - UzVy
     Ny = UzVx - UxVz
     Nz = UxVy - UyVx
     */
    
    ofVec3f U = v1-v0;
    ofVec3f V = v2-v0;
    
    normal.x = U.y*V.z - U.z*V.y;
    normal.y = U.z*V.x - U.x*V.z;
    normal.z = U.x*V.y - U.y*V.x;
    
    normal.normalize(); // unit length
    
    //normal*=.04;
}

void Face3D::calcCentroid()
{
    centroid = ofVec3f((v0.x+v1.x+v2.x)/3,
                       (v0.y+v1.y+v2.y)/3,
                       (v0.z+v1.z+v2.z)/3
                       );
   // std::cout<< "centroid = " << centroid << std::endl;
}

void Face3D::display()
{
    
    glBegin(GL_POLYGON);
    
    glNormal3f(normal.x, normal.y, normal.z);
    glVertex3f(v0.x, v0.y, v0.z);
    glVertex3f(v1.x, v1.y, v1.z);
    glVertex3f(v2.x, v2.y, v2.z);
    
    glEnd();
}

void Face3D::displayNormal(float len)
{
    
    ofPushStyle();
    
    ofNoFill();
    ofSetColor(255, 255, 255);
    glBegin(GL_LINES);
    glVertex3f(centroid.x, centroid.y, centroid.z);
    glVertex3f(centroid.x+normal.x*len, centroid.y+normal.y*len, centroid.z+normal.z*len);
    glEnd();
    
    ofPopStyle();
}







