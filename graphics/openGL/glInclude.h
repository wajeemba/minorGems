#ifdef __mac__

#include <OpenGL/gl.h>
#include <OpenGL/glu.h>


#elif defined(RASPBIAN)

// GL ES
#include <GLES/gl.h>

// some things that aren't defined in GLES or have different names
#define GLdouble     GLfloat
#define GL_CLAMP     GL_CLAMP_TO_EDGE
#define glClearDepth glClearDepthf
#define glOrtho      glOrthof
#define glFrustum    glFrustumf
#define glGetDoublev glGetFloatv
#define GL_SOURCE0_RGB GL_SRC0_RGB
#define GL_SOURCE0_ALPHA GL_SRC0_ALPHA

// regular mesa-supplied GLU should work
#include <GL/glu.h>




#else

// GL_GLEXT_PROTOTYPES must be defined before gl.h because gl.h includes
// glext.h internally, and we need the function prototypes (not just typedefs)
// for OpenGL 3.x+ functions like glGenerateMipmap.
#ifndef GL_GLEXT_PROTOTYPES
#define GL_GLEXT_PROTOTYPES 1
#endif
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glext.h>

#ifdef WIN_32
// on Windows, some stuff that's normally in gl.h (1.2 and 1.3 stuff) is
// in glext
// (already included above for all platforms)
#endif


#endif
