//
//  MyOpenGLView.h
//  mirror
//
//  Created by John Harrison on 2/25/12.
//  Copyright (c) 2012 Auburn University. All rights reserved.
//


#import <OpenGL/gl.h>
#import <OpenGL/glext.h>
#import <OpenGL/glu.h>
#import <Cocoa/Cocoa.h>

#import "GLString.h"

typedef struct {
    GLdouble x,y,z;
} recVec;

typedef struct {
	recVec viewPos; // View position
	recVec viewDir; // View direction vector
	recVec viewUp; // View up direction
	recVec rotPoint; // Point to rotate about
	GLdouble aperture; // pContextInfo->camera aperture
	GLint viewWidth, viewHeight; // current window/screen height and width
} recCamera;


@interface MirrorRenderView : NSOpenGLView
{
	// string attributes
	NSMutableDictionary * stanStringAttrib;
	
	// string textures
	GLString * helpStringTex;
	GLString * infoStringTex;
	GLString * camStringTex;
	GLString * capStringTex;
	GLString * msgStringTex;
	CFAbsoluteTime msgTime; // message posting time for expiration
	
	NSTimer* timer;
    
    bool fAnimate;
	IBOutlet NSMenuItem * animateMenuItem;
    bool fInfo;
	IBOutlet NSMenuItem * infoMenuItem;
	bool fDrawHelp;
	bool fDrawCaps;
	
	CFAbsoluteTime time;
    
	// spin
	GLfloat rRot [3];
	GLfloat rVel [3];
	GLfloat rAccel [3];
	
	// camera handling
	recCamera camera;
	GLfloat worldRotation [4];
	GLfloat objectRotation [4];
	GLfloat shapeSize;
	
}

+ (NSOpenGLPixelFormat*) basicPixelFormat;

- (void) updateProjection;
- (void) updateModelView;
- (void) resizeGL;
- (void) resetCamera;

- (void) updateObjectRotationForTimeDelta:(CFAbsoluteTime)deltaTime;
- (void)animationTimer:(NSTimer *)timer;

- (void) createHelpString;
- (void) createMessageString;
- (void) updateInfoString;
- (void) updateCameraString;
- (void) drawInfo;

-(IBAction) animate: (id) sender;
-(IBAction) info: (id) sender;

- (void)keyDown:(NSEvent *)theEvent;

- (void) mouseDown:(NSEvent *)theEvent;
- (void) rightMouseDown:(NSEvent *)theEvent;
- (void) otherMouseDown:(NSEvent *)theEvent;
- (void) mouseUp:(NSEvent *)theEvent;
- (void) rightMouseUp:(NSEvent *)theEvent;
- (void) otherMouseUp:(NSEvent *)theEvent;
- (void) mouseDragged:(NSEvent *)theEvent;
- (void) scrollWheel:(NSEvent *)theEvent;
- (void) rightMouseDragged:(NSEvent *)theEvent;
- (void) otherMouseDragged:(NSEvent *)theEvent;

- (void) drawRect:(NSRect)rect;

- (void) prepareOpenGL;
- (void) update;		// moved or resized

- (BOOL) acceptsFirstResponder;
- (BOOL) becomeFirstResponder;
- (BOOL) resignFirstResponder;

- (id) initWithFrame: (NSRect) frameRect;
- (void) awakeFromNib;


@end
