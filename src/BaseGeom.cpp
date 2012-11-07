//
//  BaseGeom.cpp
//  intro_3d
//
//  Created by Ira on 10/30/12.
//
//

#include "BaseGeom.h"


std::ostream& operator<<(std::ostream& output, const BaseGeom& baseGeom)
{
    output << "BaseGeom obj: [ loc = "<<baseGeom.loc<<" rot = "<<baseGeom.rot<<" dim = "<<baseGeom.dim<<" color = "<<baseGeom.color<<" ]";
    return output;
}


BaseGeom::BaseGeom()
{
   std::cout<< "In BaseGeom Constructor"<< std::endl; 
}

BaseGeom::BaseGeom(const ofVec3f& loc, const ofVec3f& rot, const Dimension3D& dim, const Color4f& color):
loc(loc), rot(rot), dim(dim), color(color)
{
    
}

void BaseGeom::move()
{
    loc += 5;
}

void BaseGeom::init()
{
    std::cout<< "In init"<< std::endl;
    clearAll();
    calcVerts();
    calcInds();
    calcFaces();
}


void BaseGeom::calcFaces()
{
    //std::cout << "in calcFaces" << std::endl;
    for (int i=0; i<indices.size(); i++){
        ofVec3f v0 = verts.at(indices.at(i).elem0);
        ofVec3f v1 = verts.at(indices.at(i).elem1);
        ofVec3f v2 = verts.at(indices.at(i).elem2);
        faces.push_back(Face3D(v0, v1, v2));
    }
    
}

void BaseGeom::display()
{
    glPushMatrix();
    glTranslatef(loc.x, loc.y, loc.z);
    glScalef(dim.w, dim.h, dim.d);
    glRotatef(rot.x++, 1, 1, 1);
    glColor3f(color.r, color.g, color.b);
    for (int i=0; i<faces.size(); i++){
        faces.at(i).display();
    }
    glPopMatrix();
}


void BaseGeom::clearAll()
{
    if(verts.size()>0){
        verts.clear();
    }
    if(indices.size()>0){
        indices.clear();
    }
}

void BaseGeom::displayNormal(float len)
{
    glPushMatrix();
    glTranslatef(loc.x, loc.y, loc.z);
    glScalef(dim.w, dim.h, dim.d);
    glRotatef(rot.x, 1, 1, 1);
    for (int i=0; i<faces.size(); i++){
        faces.at(i).displayNormal(len);
    }
     glPopMatrix();
}


















