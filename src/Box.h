//
//  Box.h
//  intro_3d
//
//  Created by Ira on 10/30/12.
//
//

#ifndef intro_3d_Box_h
#define intro_3d_Box_h

#include "BaseGeom.h"
class Box : public BaseGeom {
    
public:
    Box();
    Box(const ofVec3f& loc, const ofVec3f& rot, const Dimension3D& dim, const Color4f& color, float mass);
    void calcVerts();
    void calcInds();
private:
    float mass;
};

#endif
