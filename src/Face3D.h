//
//  Face3D.h
//  animatingParticles
//  automicatlly calculates face normals
//
//  Created by Ira on 8/30/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef animatingParticles_Face3D_h
#define animatingParticles_Face3D_h

#include "ofMain.h"


class Face3D {
    
public:
    
    Face3D(const ofVec3f& v0, const ofVec3f& v1, const ofVec3f& v2);
    
    ofVec3f v0, v1, v2;
    ofVec3f normal, centroid;
    ofVec3f* vecs; // pointer to array
    ofVec3f* p_vecs[3]; // array of vec pointers
    
    ofVec3f& getNormal();
    
    void display();
    void displayNormal(float len = .1);
    
private:
    void calcNormal();
    void calcCentroid();
    
    
};

#endif
