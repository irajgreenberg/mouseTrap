//
//  BaseGeom.h
//  intro_3d
//
//  Created by Ira on 10/30/12.
//
//

#ifndef intro_3d_BaseGeom_h
#define intro_3d_BaseGeom_h

#include "ofMain.h"
#include "Dimension3D.h"
#include "Face3D.h"
#include "Color4f.h"
#include <vector>
#include "Tuple3i.h"

class BaseGeom {
    
protected:
    ofVec3f loc, rot;
    Color4f color;
    Dimension3D dim;
    std::vector<Face3D> faces;
    std::vector<ofVec3f> verts;
    std::vector<Tuple3i> indices;
    
    // this CAN be overridden
    // need to use virtual keyword
    
    // if = 0, then this method is a
    // pure virtual method and MUST be
    // overridden
    virtual void init();
    virtual void calcVerts() = 0;
    virtual void calcInds() = 0;
   

public:
    friend std::ostream& operator<<(std::ostream& output, const BaseGeom& baseGeom);
    
    BaseGeom();
    BaseGeom(const ofVec3f& loc, const ofVec3f& rot, const Dimension3D& dim, const Color4f& color);
    
    // these will not be overridden by subclasses
    void calcFaces();
    void move();
    void display();
    void clearAll();
    void displayNormal(float len);
    
    
};
#endif



