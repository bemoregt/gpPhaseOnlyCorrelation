#include "ofApp.h"

using namespace ofxCv;
//--------------------------------------------------------------
void ofApp::setup(){
    
    kernelSize = 3;
    
    filePath1 = "/Users/kerbal/Desktop/left.png";
    before1.load(filePath1);
    filePath2 = "/Users/kerbal/Desktop/right.png";
    before2.load(filePath2);

}

//--------------------------------------------------------------
void ofApp::update(){

    
    cv::Mat mat1, mat2;
    // convert & gray
    mat1 = toCv(before1);
    cv::cvtColor(mat1, mat1, CV_BGR2GRAY);
    mat2 = toCv(before2);
    cv::cvtColor(mat2, mat2, CV_BGR2GRAY);
    
    // resize
    float ratio = 256.0 / mat2.cols;
    cv::resize(mat1, mat1, cv::Size(mat1.cols*ratio, mat1.rows*ratio));
    cv::resize(mat2, mat2, cv::Size(mat2.cols*ratio, mat2.rows*ratio));
    
    cv::Mat hann;
    cv::createHanningWindow(hann, mat1.size(), CV_64F);
    //
    cv::Mat left64f, right64f;
    mat1.convertTo(left64f, CV_64F);
    mat2.convertTo(right64f, CV_64F);
    // poc
    cv::Point2d shift = phaseCorrelate(left64f, right64f, hann);
    // radius
    double radius = std::sqrt(shift.x*shift.x + shift.y*shift.y);
    
    if(radius > 1)
    {
        // draw a circle and line indicating the shift direction...
        cv::Point center(mat1.cols >> 1, mat1.rows >> 1);
        cv::circle(mat1, center, (int)radius, cv::Scalar(255, 0, 0), 1, cv::LINE_AA);
        line(mat1, center, cv::Point(center.x + (int)shift.x, center.y + (int)shift.y), cv::Scalar(255, 0, 0), 1, cv::LINE_AA);
    }
    // update spectrum
    cv::normalize(mat1, mat1, 255, 0, cv::NORM_MINMAX, CV_8U);
    toOf(mat1, after);
    after.update();
}

//--------------------------------------------------------------
void ofApp::draw(){

    ofSetColor(255,255,255);
    before1.draw(0, 0, 512, 512);
    before2.draw(512, 0, 512, 512);
    after.draw(1024, 0, 512, 512);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    //
    if(key=='s') {
        string filename = ofGetTimestampString()+".png";
        std::cout << "save to "<< filename <<std::endl;
        
        //std::cout << "original size: " << original.getWidth()
        //<< " " << original.getHeight() <<std::endl;
        after.update();
        after.save(filename);
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
