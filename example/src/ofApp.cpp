#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofEnableAlphaBlending();
    ofSetCircleResolution(100);
    
    width = ofGetWidth();
    height = ofGetHeight();

    // Initial Allocation
    //
    fluid.allocate(width, height, 0.25);
    
    // Seting the gravity set up & injecting the background image
    //
    fluid.dissipation = 0.99;
    fluid.velocityDissipation = 0.99;
    
    fluid.setGravity(ofVec2f(0.0,0.0));
    //fluid.setGravity(ofVec2f(0.0,0.0098));
    

    
    // Adding constant forces
    //
    fluid.addConstantForce(glm::vec2(width*0.5,height*0.85), glm::vec2(0,-2), ofFloatColor(0.5,0.1,0.0), 10.f);
}

//--------------------------------------------------------------
void ofApp::update(){
    
    //  Set obstacle
    //
    fluid.obstaclesFbo.begin();
    float w = fluid.obstaclesFbo.getWidth();
    float h = fluid.obstaclesFbo.getHeight();
    ofClear(0, 0);
    ofSetColor(0,0);
    ofSetColor(255);
    glm::vec2 p;
    p.x = (w/2.0) + cos(ofGetElapsedTimef()*.8) * (w/2.0);
    p.y = h * 0.3;
    ofDrawCircle(p, w*0.1);
    fluid.obstaclesFbo.end();
    fluid.setUseObstacles(true);

    
    
    // Adding temporal Force
    //
    glm::vec2 m = glm::vec2(mouseX,mouseY);
    glm::vec2 d = (m - oldM) * 10.0;
    oldM = m;
    glm::vec2 c = glm::vec2(640*0.5, 480*0.5) - m;
    c = glm::normalize(c);
    
    
    ofFloatColor color = ofFloatColor(c.x,c.y,0.5) * sin(ofGetElapsedTimef());
    fluid.addTemporalForce(m, d, color, 3.0f);
    
    //  Update
    //
    fluid.update();
    
    ofSetWindowTitle(ofToString(ofGetFrameRate()));
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackgroundGradient(ofColor::gray, ofColor::black, OF_GRADIENT_LINEAR);
    
    fluid.draw();
    //fluid.drawVelocity();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
