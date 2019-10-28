#include "ofApp.h"


void ofApp::setup(){
    gui.setup("panel");
    gui.add(displacement.set("displacement", 0));
    gui.add(speed.set("speed", 0));
    gui.add(numTriangles.set("numTriangles", 20, 1, 50));
    
    hideGui = false;
}

void ofApp::update(){

}

ofPolyline line;
void triangleWithFaces(int size, int numFaces) {
    for (float i = 0; i <= 2*PI; i+=(2*PI)/numFaces) {
        float x = size * cos(i);
        float y = size * sin(i);
        line.addVertex(x, y);
    }
    line.close();
    line.draw();
    line.clear();
}

void triangleCircle(int sides, float phase, float ldisplacement, int numTriangles) {
    float width = ofGetWidth() - 300;
    float height = ofGetHeight();
    
    float size = width / 1.4;
    float scaleEnd = 3*PI;
    for (float i = 0; i <= scaleEnd; i+=scaleEnd/numTriangles) {
        float curTime = ofGetElapsedTimef();
        float x = size * cos(phase*curTime + i);
        float y = size * sin(phase*curTime + i);
        ofPushMatrix();
        ofTranslate(width / 2, height / 2);
        ofTranslate(x * ldisplacement, y * ldisplacement);
        ofRotateDeg(-90);
        float scale = ofMap(i, 0, scaleEnd, 10, 300);
        ofScale(scale);
        triangleWithFaces(1, sides);
        ofPopMatrix();
    }
}

void ofApp::draw(){
    ofBackground(0);
    
    ofNoFill();
    ofSetLineWidth(2.5);
    
    ofPushMatrix();
    ofSetColor(100, 100, 100);
    ofTranslate(300, 0);
    cout << numTriangles.get() << endl;
    triangleCircle(40, speed.get(), displacement.get(), numTriangles.get());
    ofPopMatrix();
    
    ofPushMatrix();
    ofSetColor(255, 0, 0);
    ofTranslate(0, 0);
    triangleCircle(40, speed.get(), displacement.get(), numTriangles.get());
    ofPopMatrix();
    
    if (!hideGui) {
        gui.draw();
    }
}

void ofApp::keyPressed(int key){
    if (key == 'h') {
        hideGui = !hideGui;
    }
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
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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
