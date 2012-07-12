#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    ofBackground(64);
    glEnable(GL_DEPTH_TEST);
    
    float size = 100;
    
    //this is pretty much like ofBox is doing it internally
    //stolen from https://github.com/openframeworks/openFrameworks/blob/master/libs/openFrameworks/graphics/ofGraphics.cpp#L915
    
    float h = size * .5;
    
    ofVec3f vertices[] = {
        ofVec3f(+h,-h,+h), ofVec3f(+h,-h,-h), ofVec3f(+h,+h,-h), ofVec3f(+h,+h,+h),
        ofVec3f(+h,+h,+h), ofVec3f(+h,+h,-h), ofVec3f(-h,+h,-h), ofVec3f(-h,+h,+h),
        ofVec3f(+h,+h,+h), ofVec3f(-h,+h,+h), ofVec3f(-h,-h,+h), ofVec3f(+h,-h,+h),
        ofVec3f(-h,-h,+h), ofVec3f(-h,+h,+h), ofVec3f(-h,+h,-h), ofVec3f(-h,-h,-h),
        ofVec3f(-h,-h,+h), ofVec3f(-h,-h,-h), ofVec3f(+h,-h,-h), ofVec3f(+h,-h,+h),
        ofVec3f(-h,-h,-h), ofVec3f(-h,+h,-h), ofVec3f(+h,+h,-h), ofVec3f(+h,-h,-h)
    };
    myMesh.addVertices(vertices,24);
    
    static ofVec3f normals[] = {
        ofVec3f(+1,0,0), ofVec3f(+1,0,0), ofVec3f(+1,0,0), ofVec3f(+1,0,0),
        ofVec3f(0,+1,0), ofVec3f(0,+1,0), ofVec3f(0,+1,0), ofVec3f(0,+1,0),
        ofVec3f(0,0,+1), ofVec3f(0,0,+1), ofVec3f(0,0,+1), ofVec3f(0,0,+1),
        ofVec3f(-1,0,0), ofVec3f(-1,0,0), ofVec3f(-1,0,0), ofVec3f(-1,0,0),
        ofVec3f(0,-1,0), ofVec3f(0,-1,0), ofVec3f(0,-1,0), ofVec3f(0,-1,0),
        ofVec3f(0,0,-1), ofVec3f(0,0,-1), ofVec3f(0,0,-1), ofVec3f(0,0,-1)
    };
    myMesh.addNormals(normals, 24);
    
    static ofIndexType indices[] = {
        0,1,2,
        0,2,3,
        4,5,6,
        4,6,7,	
        8,9,10,
        8,10,11,
        12,13,14,
        12,14,15,
        16,17,18,
        16,18,19,
        20,21,22,
        20,22,23
    };
    myMesh.addIndices(indices,36);   
}

//--------------------------------------------------------------
void testApp::update() {
    myLight.setPosition(myCam.getPosition());
}

//--------------------------------------------------------------
void testApp::draw() {
    myCam.begin();
    ofEnableLighting();
    myLight.enable();
    myMaterial.begin();
    
    myMesh.draw();
    
    myMaterial.end();
    myLight.disable();
    ofDisableLighting();
    drawDebugInfo();
    myCam.end();
}

void testApp::drawDebugInfo() {
    int size = 300;
    
    ofSetColor(80);
    for (int i = -size; i <= size; i = i + 50) {
        if (i != 0) {
            ofLine(-size, 0, i, size, 0, i);
            ofLine(i, 0, -size, i, 0, size);
        }
    }
    ofSetColor(255, 0, 0);
    ofLine(-size, 0, 0, size, 0, 0);
    ofSetColor(0, 255, 0);
    ofLine(0, -size, 0, 0, size, 0);
    ofSetColor(0, 0, 255);
    ofLine(0, 0, -size, 0, 0, size);
    ofSetColor(255, 255, 255);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 
    
}