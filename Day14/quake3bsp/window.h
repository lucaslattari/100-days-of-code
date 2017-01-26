#ifndef _WINDOW_H_
#define _WINDOW_H_

#define GLUT_DISABLE_ATEXIT_HACK

#include <GL/glew.h>
#include <GL/freeglut.h>
#include <string>

using namespace std;

class Window
{
private:
public:
    Window();
    ~Window();

    void setWindowPosition(int x, int y);
    void setWindowSize(int width, int height);
    void createWindow(string name);
    void calledWhenWindowIsRedrawed(void (*argumentFunction) ());
    void calledWhenWindowIsReshaped(void (*argumentFunction) (int, int));
    void calledWhenMouseEventOccurs(void (*argumentFunction) (int, int, int, int));
    void calledWhenMouseMoves(void (*argumentFunction) (int, int));
    void calledWhenIdle(void (*argumentFunction) ());
    void repeatLoop();
};

#endif // _WINDOW_H_
