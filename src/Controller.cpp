#include "Controller.h"




//============================================================================
// Lighting variables
//============================================================================

// Basic 3-point lighting setup (Key, Fill, Back)
// light0 - Key
float light0Ambient[] = { .4, .4, .4, 0};
float light0Diffuse[] = {1, 1, 1, 0 }; // warmer
float light0Specular[] = {  1, 1, 1, 1 };
float light0Pos[4] = { 30, -150, 100, 0 };  // 4th arg 0=infinity, 1=position


// Materials
float mat_specular[] = { 1.0, .5, 1.0, 1.0 };
float mat_shininess[] = { 128 }; // use range 0 to 128


//--------------------------------------------------------------
void Controller::setup(){
    
    // environment states
	ofBackground(0,0,0);
	ofSetWindowTitle("Introduction to 3D");
    ofSetFrameRate(60);
    
    // coordiates FPS with monitor's refresh rate - FPS will max out at your refresh rate
    ofSetVerticalSync(true); // is this necessary
    
	// Set the camera's distance from the object
	cam.setDistance(0);
    
    // allow mouse interactivity
    cam.enableMouseInput();
    
    
    glShadeModel (GL_FLAT); // enable flat shading
    glShadeModel (GL_SMOOTH); // enable smooth shading
    
    // enable some 3D face sorting
    glEnable (GL_DEPTH_TEST);
    
    // Explicitely set face winding rule
    glFrontFace(GL_CCW); // or GL_CW
    
    // Hide back faces of surfaces
    glEnable(GL_CULL_FACE);
    
    // enable alpha
    // not fully implemented
    glEnable (GL_BLEND);
    glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    
    // keep normals updated and normalized (length=1)
    glEnable(GL_NORMALIZE);
    
    setLighting();
    
    b = Box(ofVec3f(100, 100, -50), ofVec3f(), Dimension3D(200, 200, 200), Color4f(.5, 1, .25), 2);
    
    // Array of boxes
    float cellW = ofGetWidth()/COLS;
    float cellH = ofGetHeight()/ROWS;
    forms = new BaseGeom*[COLS*ROWS];
    for(int i=0; i<ROWS; i++){
        for(int j=0; j<COLS; j++){
            /*boxes[i][j] = Box(ofVec3f(cellW/2 + cellW*j, cellH/2 + cellH*i, 0), ofVec3f(ofRandom(360),
                        ofRandom(360), ofRandom(360)), Dimension3D(cellW*.5, cellH*.5, cellW*.5),
                        Color4f(Color4f(ofRandom(1), ofRandom(1), ofRandom(1))), 2);*/
            
            switch(int(ofRandom(3))){
            case 0:
                forms[i*COLS+j] = new Box(ofVec3f(cellW/2 + cellW*j, cellH/2 + cellH*i, 0),
                                          ofVec3f(ofRandom(360), ofRandom(360), ofRandom(360)),
                                          Dimension3D(cellW*.5, cellH*.5, cellW*.5),
                                          Color4f(Color4f(ofRandom(1), ofRandom(1), ofRandom(1))), 2);
                break;
            case 1:
                    forms[i*COLS+j] = new Toroid(ofVec3f(cellW/2 + cellW*j, cellH/2 + cellH*i, 0),
                                                 ofVec3f(ofRandom(360), ofRandom(360), ofRandom(360)),
                                                 Dimension3D(cellH*.5, cellH*.5, cellH*.5),
                                                 Color4f(Color4f(ofRandom(1), ofRandom(1), ofRandom(1))), 60, 80, ofRandom(.06, .25));
                break;
            case 2:
                    forms[i*COLS+j] =  new Icosahedron(ofVec3f(cellW/2 + cellW*j, cellH/2 + cellH*i, 0),
                                                       ofVec3f(ofRandom(360), ofRandom(360), ofRandom(360)),
                                                       Dimension3D(cellH*.5, cellH*.5, cellH*.5),
                                                       Color4f(Color4f(ofRandom(1), ofRandom(1), ofRandom(1))));
                break;
                
            }
            rots[i*COLS+j] = ofVec3f(ofRandom(5), ofRandom(5), ofRandom(5));
        }
    }
    
    // toroids
    toroid =  Toroid(ofVec3f(0, 0, 0), ofVec3f(0, 0, 0), Dimension3D(240, 240, 240), Color4f(ofRandom(1), ofRandom(1), ofRandom(1)), 60, 80, .08);
    toroid2 =  Toroid(ofVec3f(0, 0, 0), ofVec3f(ofRandom(360), ofRandom(360), ofRandom(360)), Dimension3D(140, 140, 140), Color4f(ofRandom(1), ofRandom(1), ofRandom(1)), 60, 80, .12);
    
    std::cout<< "toroid = " << toroid << std::endl;
    
    ico = new Icosahedron(ofVec3f(0, 0, 0), ofVec3f(15, 30, 100), Dimension3D(90, 90, 90), Color4f(ofRandom(1), ofRandom(1), ofRandom(1)));
}

//============================================================================
// Set up the lighting
//============================================================================
void Controller::setLighting(){
    
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
    glColorMaterial(GL_FRONT,GL_DIFFUSE);
    //glColorMaterial(GL_FRONT,GL_SPECULAR);
    
    // light0
    glLightfv(GL_LIGHT0, GL_POSITION, light0Pos);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light0Diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light0Specular);
    glLightfv(GL_LIGHT0, GL_AMBIENT, light0Ambient);
    
    
    // enable the lights/materials
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_SPECULAR); // does this do anything
    glEnable(GL_AMBIENT);  // does this do anything
    glEnable(GL_LIGHTING);
    
    glEnable(GL_LIGHT0);
}

//--------------------------------------------------------------
void Controller::update(){
}

//--------------------------------------------------------------
void Controller::draw(){
    cam.begin();
    
    
    glPushMatrix();
    glTranslatef(-ofGetWidth()/2,-ofGetHeight()/2, -10);
    for(int i=0; i<ROWS; i++){
        for(int j=0; j<COLS; j++){
            glEnable(GL_LIGHTING);
            //glPushMatrix();
            //ofRotate(rots[i*COLS+j].x++, 1, 0, 0);
            //ofRotate(rots[i*COLS+j].y++, 0, 1, 0);
            //ofRotate(rots[i*COLS+j].z++, 0, 0, 1);
            forms[i*COLS+j]->display();
            //glPopMatrix();
            //boxes[i][j].display();
            
            glDisable(GL_LIGHTING);
            //boxes[i][j].displayNormal(.3);
        }
    }
    glPopMatrix();
    
    glEnable(GL_LIGHTING);
    //toroid.display();
    //toroid2.display();
    
    glEnable(GL_LIGHTING);
    //ico->display();
    glDisable(GL_LIGHTING);
    //ico->displayNormal(.3);
    
    cam.end();
}

//--------------------------------------------------------------
void Controller::keyPressed(int key){
    
}

//--------------------------------------------------------------
void Controller::keyReleased(int key){
    
}

//--------------------------------------------------------------
void Controller::mouseMoved(int x, int y){
    
}

//--------------------------------------------------------------
void Controller::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void Controller::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void Controller::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void Controller::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void Controller::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void Controller::dragEvent(ofDragInfo dragInfo){
    
}