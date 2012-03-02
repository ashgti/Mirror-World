//
//  drawInfo.h
//  mirror
//
//  Created by John Harrison on 3/2/12.
//  Copyright (c) 2012 Auburn University. All rights reserved.
//

#ifndef mirror_drawInfo_h
#define mirror_drawInfo_h

#import <OpenGL/gl.h>

// call after OpenGL caps are found
void initCapsTexture (GLCaps * displayCaps, CGDisplayCount numDisplays);

// get NSString with caps for this renderer
void drawCaps (GLCaps * displayCaps, CGDisplayCount numDisplays, long renderer, GLfloat width); // view width for drawing location


#endif
