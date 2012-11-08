//
//  Icosahedron.h
//  intro_3d
//
//  Created by Ira on 11/8/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef intro_3d_Icosahedron_h
#define intro_3d_Icosahedron_h

#include "BaseGeom.h"
class Icosahedron : public BaseGeom {
    
public:
    Icosahedron();
    Icosahedron(const ofVec3f& loc, const ofVec3f& rot, const Dimension3D& dim, const Color4f& color, float mass);
    void calcVerts();
    void calcInds();
private:
    static const int PENTAGON_ARR_LEN = 5;
    static const float PHI = 1.25663706144;    
};


#endif
