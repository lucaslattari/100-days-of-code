#include "window.h"

Window::Window()
{
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGB);
}

Window::~Window()
{

}

void Window::setWindowPosition(int x, int y)
{
    glutInitWindowPosition(x, y);
}

void Window::setWindowSize(int width, int height)
{
    glutInitWindowSize(width, height);
}

void Window::createWindow(string name)
{
    glutCreateWindow(name.c_str());
}

void Window::calledWhenWindowIsRedrawed(void (*argumentFunction)())
{
    glutDisplayFunc(argumentFunction);
}

void Window::calledWhenWindowIsReshaped(void (*argumentFunction) (int, int))
{
    glutReshapeFunc(argumentFunction);
}

void Window::calledWhenMouseEventOccurs(void (*argumentFunction) (int, int, int, int))
{
    glutMouseFunc(argumentFunction);
}

void Window::calledWhenMouseMoves(void (*argumentFunction) (int, int))
{
    glutMotionFunc(argumentFunction);
}

void Window::calledWhenIdle(void (*argumentFunction) ())
{
    glutIdleFunc(argumentFunction);
}

void Window::repeatLoop()
{
    glutMainLoop();
}
