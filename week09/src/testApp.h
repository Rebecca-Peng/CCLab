//
//  testApp.hpp
//  mySketch
//
//  Created by pfy on 11/7/16.
//
//

#ifndef testApp_hpp
#define testApp_h

#include <stdio.h>
class testApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed  (int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    ofImage img;
    ofShader shader;
    ofFbo fbo;
    
    float len;
    bool bAdd;
};

#endif /* testApp_hpp */
