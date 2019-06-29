#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofEnableAlphaBlending();
    ofSetCircleResolution(100);
    
    width = 300;
    height = 600;

    // Initial Allocation
    //
    fluid.allocate(width, height, 0.5);
    
    // Seting the gravity set up & injecting the background image
    //
    fluid.dissipation = 0.99;
    fluid.velocityDissipation = 0.99;
    
    fluid.setGravity(ofVec2f(0.0,0.0));
//    fluid.setGravity(ofVec2f(0.0,0.0098));
    
    //  Set obstacle
    //
//    fluid.begin();
//    ofSetColor(0,0);
//    ofSetColor(255);
//    ofDrawCircle(width*0.5, height*0.35, 40);
//    fluid.end();
    fluid.setUseObstacles(false);
    
    // Adding constant forces
    //
    fluid.addConstantForce(ofPoint(width*0.5,height*0.85), ofPoint(0,-2), ofFloatColor(0.5,0.1,0.0), 10.f);

    ofSetWindowShape(width, height);
}

//--------------------------------------------------------------
void ofApp::update(){
    
    // Adding temporal Force
    //
    ofPoint m = ofPoint(mouseX,mouseY);
    ofPoint d = (m - oldM)*10.0;
    oldM = m;
    ofPoint c = ofPoint(640*0.5, 480*0.5) - m;
    c.normalize();
    fluid.addTemporalForce(m, d, ofFloatColor(c.x,c.y,0.5)*sin(ofGetElapsedTimef()),3.0f);

    //  Update
    //
    fluid.update();
    
    ofSetWindowTitle(ofToString(ofGetFrameRate()));
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackgroundGradient(ofColor::gray, ofColor::black, OF_GRADIENT_LINEAR);
    
    fluid.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if( key == 'p')
        bPaint = !bPaint;
    if( key == 'o')
        bObstacle = !bObstacle;
    if( key == 'b')
        bBounding = !bBounding;
    if( key == 'c')
        bClear = !bClear;
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}
