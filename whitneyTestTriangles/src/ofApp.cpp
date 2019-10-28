#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
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

void triangleStack(float trDelta) {
    float elapsedTime = ofGetElapsedTimef();
    float deltaTransform = 1.0+0.6*sin(elapsedTime);
    int numShapes = ofMap(ofGetMouseX(), 0, 800, 10, 100);
    for (int i = 0; i < numShapes; i++) {
        ofPushMatrix();
        float scale = ofMap(i, 0, numShapes, 0.2, 1.2);
        ofScale(scale, scale);
        float moveAmount = ofMap(sin(i*0.4+elapsedTime), -1, 1, -100, 100);
        ofTranslate(moveAmount, -1*cos(i*0.2)*moveAmount);
        ofTranslate(400, 400);
        float rotate = (elapsedTime*10);//ofMap(sin(elapsedTime*0.4)+sin(i*0.2)*0.3, -1, 1, 0, 360);
        ofRotateDeg(rotate);
        triangleWithFaces(200, 3);
        ofPopMatrix();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
    ofSetColor(255, 0, 0);
    ofNoFill();
    ofSetLineWidth(2.6);
    triangleStack(0);
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
