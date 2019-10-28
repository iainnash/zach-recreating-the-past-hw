#include "ofApp.h"

void ofApp::loadFontAtIndex() {
    ofDirectory dir("fonts");
    dir.allowExt("ttf");
    dir.listDir();

    if (atIndex >= dir.size()) {
        atIndex = 0;
    }
    
    font.load(dir.getPath(atIndex), 500, true, true, true);
    fontSmall.load(dir.getPath(atIndex), 10);
    fontName = dir.getName(atIndex);
    fontName = fontName.substr(0, fontName.size() - 4);
}

//--------------------------------------------------------------
void ofApp::setup(){
    fbo.allocate(1000, 1000, GL_RGBA);
    currentChar = 'A';
    
    loadFontAtIndex();
}

//--------------------------------------------------------------
void ofApp::update(){

}

void ofApp::draw(){
    ofBackground(255);
    ofSeedRandom(10);
    
    string textToDraw;
    textToDraw += currentChar;
    
    ofRectangle boxLarge = font.getStringBoundingBox(textToDraw, 0, 0);
    ofRectangle boxSmall = fontSmall.getStringBoundingBox(fontName, 0, 0);
    
    fbo.begin();
    ofTranslate((ofGetWidth()/2)-boxLarge.width/2, (ofGetHeight()/2)+boxLarge.height/2);
    ofClear(0);
    ofSetColor(255);
    font.drawString(textToDraw, 0, 0);
    fbo.end();
    ofPixels savedPixels;
    fbo.readToPixels(savedPixels);
    
    ofSetColor(235, 255);
    fbo.draw(-10, -10);
    ofSetColor(0, 100);
    
    for (int yi = 0; yi < fbo.getHeight(); yi += boxSmall.height) {
        bool hasDrawn = false;
        for (int xi = 0; xi < fbo.getWidth(); xi += hasDrawn ? boxSmall.width : boxSmall.height) {
            if (savedPixels.getColor(xi, yi).r) {
                hasDrawn = true;
                fontSmall.drawString(
                    fontName,
                    xi - boxSmall.width / 2 + ofRandom(-2, 2),
                    yi - boxSmall.height / 2 + ofRandom(-2, 2)
                );
            } else {
                hasDrawn = false;
            }
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key >= 'a' && key <= 'z') {
        currentChar = key + 'A' - 'a';
    }
    if (key >= 'A' && key <= 'Z') {
        currentChar = key;
    }
    if (key == '!') {
        atIndex++;
        loadFontAtIndex();
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
