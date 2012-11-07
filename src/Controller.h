#pragma once

#include "ofMain.h"
#include "Color4f.h"
#include "Box.h"
#include "Toroid.h"



class Controller : public ofBaseApp{

public:
    
    
    Box b;
    Toroid toroid, toroid2;
    //std::vector<Box> boxes;
    static const int ROWS = 10;
    static const int COLS = 10;
    Box boxes[ROWS][COLS];
    
    ofEasyCam cam; // add mouse controls for camera movement
    
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y);
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    void setLighting();
};
