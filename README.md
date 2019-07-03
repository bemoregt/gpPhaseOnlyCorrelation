# ofxPhaseOnlyCorrelation
Phase Only Correlation for Openframeworks C++ using ofxCv

![POC example]( https://github.com/bemoregt/ofxPhaseOnlyCorrelation/blob/master/result.png "POC")
- White Circle Radius means translation magnitude between first & second images. 
- White Radius Vector means translation direction between first & second images.

### Algorithm
- POC is a kind of template matching A/G that use 2D FFT. 
- POC shows more sharp matching peaks than template matching of spatial domain because of only phase information.

### Dependency
- OpenFrameworks 0.10.1
- ofxCv
- ofxOpenCv
- ofxGUI
- XCode 10.12.x
- OSX Mojave

### Next Plan
- Color Graphics
- Realtime VideoFile POC
- Realtime WebCam POC


