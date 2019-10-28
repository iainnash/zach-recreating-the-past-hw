#include "ofApp.h"

void ofApp::loadFontAtIndex() {
    ofDirectory dir("fonts");
    //only show png files
    dir.allowExt("ttf");
    //populate the directory object
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
    currentChar = 'A';
    
    loadFontAtIndex();
}

//--------------------------------------------------------------
void ofApp::update(){

}
/*
//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
    //ofSetColor(250);
    
    // get the string as paths
    bool vflip = true; // OF flips y coordinate in the default perspective,
                      // should be false if using a camera for example
    bool filled = true; // or false for contours
    string toPrint;
    toPrint+="OK";
    toPrint += currentChar;
       
    vector <ofPath> paths = font.getStringAsPoints(toPrint, vflip, filled);

    ofPushMatrix();
    //ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    ofTranslate(300,300);
    
    for (int i = 0; i < paths.size(); i++){
    
        vector < ofPolyline > lines = paths[i].getOutline();
        
        for (int j = 0; j < lines.size(); j++){
            
            ofPolyline temp = lines[j].getResampledBySpacing(4);
            for (int k = 0; k < temp.size(); k++){
                temp[k].x += 50 * sin(temp[k].y*0.04 + ofGetElapsedTimef());
            }
            //temp = temp.getSmoothed(MAX(mouseX, 1));
            temp.draw();
            //temp.draw();
            //for (int k = 0; k < temp.getVertices().size(); k++){
                //ofDrawCircle(temp.getVertices()[k], 2);
            //}
        }
    }
 
    for (int i = 0; i < paths.size(); i++){
        //paths[i].draw();
        //vector <ofPolyline> polylines = paths[i].getOutline();
        
        ofPolyline temp = lines[j].getResampledBySpacing(4);
        for (int k = 0; k < temp.getVertices().size(); k++){
        
        for (int j = 0; j < polylines.size(); j++){
            for (int k = 0; k < polylines[j].size(); k += 5){
                ofDrawCircle(polylines[j][k], 3);
            }
        }
    }
    ofPopMatrix();
}
*/


void ofApp::draw(){
    ofBackground(255);
    float tm = ofGetElapsedTimef()/4;
    int noiseCount = 0;
    
    string textToDraw;
    textToDraw += currentChar;
                                                           //   vflip, filled
    vector < ofPath > paths = font.getStringAsPoints(textToDraw, true, false);
    
    ofRectangle boxLarge = font.getStringBoundingBox(textToDraw, 0, 0);
    
    ofTranslate((ofGetWidth()/2)-boxLarge.width/2, (ofGetHeight()/2)+boxLarge.height/2);

    ofSetColor(200);
    font.drawString(textToDraw, 0, 0);
    
    ofSetColor(0, 0, 0, 100);
    
    auto bbox = fontSmall.getStringBoundingBox(fontName, 0, 0);
    
    for (int i = 0; i < paths.size(); i++){
        
        vector < ofPolyline > lines = paths[i].getOutline();
        
        for (int j = 0; j < lines.size(); j++){
            
            ofPolyline temp = lines[j].getResampledBySpacing(8);
            for (int k = 0; k < temp.size(); k++){
                int offset = ofMap(ofNoise(tm + k*0.1, tm + j*0.1), 0, 1, -5, 5);
                fontSmall.drawString(fontName, temp[k].x - bbox.width / 2 + offset, temp[k].y - bbox.height / 2 + offset);
            }
            //temp = temp.getSmoothed(MAX(mouseX, 1));
            //temp.draw();
            
//            for (int k = 0; k < temp.getVertices().size(); k++){
//                ofDrawCircle(temp.getVertices()[k], 2);
//            }
            
//            ofPolyline temp = lines[j].getSmoothed(MAX(1, mouseX));
//            temp.draw();
        }
        
        
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key >= 'a' && key <= 'z') {
        currentChar = key;// + 'A' - 'a';
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
