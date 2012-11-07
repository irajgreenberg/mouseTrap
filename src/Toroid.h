//
//  Toroid.h
//  intro_3d
//
//  Created by Ira on 10/6/12.
//
//

#ifndef Protobyte_iig001_Toroid_h
#define Protobyte_iig001_Toroid_h

#include "BaseGeom.h"
#include "Dimension3D.h"
#include "Color4f.h"

    
    class Toroid: public  BaseGeom {
        
    public:
        friend std::ostream& operator<<(std::ostream& output, const Toroid& toroid);
        
        explicit Toroid(const ofVec3f& loc = ofVec3f(0,0,0), const ofVec3f& rot = ofVec3f(0,0,0), const Dimension3D& dim = Dimension3D(1,1,1), const Color4f& color = Color4f(.5, .5, .5, .5), int ringCount = 12, int ringDetail = 20, float ringRadius = .2);
        
        // overrides base class
        void calcVerts();
        void calcInds();
        
        
        // getters & setters
        int getRingCount() const;
        void setRingCount(int ringCount);
        int getRingDetail() const;
        void setRingDetail(int ringDetail);
        float getRingRadius() const;
        void setRingRadius(float ringRadius);
        
    private:
        int ringCount;
        int ringDetail;
        float ringRadius;
    };
    


#endif
