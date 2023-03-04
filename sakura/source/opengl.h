#ifndef _OPENGL_
#define _OPENGL_

typedef void (APIENTRY* glBegin_t)(GLenum);
typedef BOOL(APIENTRY* wglSwapBuffers_t)(HDC  hdc);
typedef void (APIENTRY* glClear_t)(GLbitfield mask);
typedef void (APIENTRY* glColor4f_t)(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
typedef void(__stdcall* glReadPixels_t)(GLint, GLint, GLsizei, GLsizei, GLenum, GLenum, GLvoid*);
typedef void (APIENTRY* glVertex3fv_t)(GLfloat* v);

extern glBegin_t pglBegin;
extern wglSwapBuffers_t pwglSwapBuffers;
extern glClear_t pglClear;
extern glColor4f_t pglColor4f;
extern glReadPixels_t pglReadPixels;
extern glVertex3fv_t pglVertex3fv;

void HookOpenGL();

#endif