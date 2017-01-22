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

void Window::repeatLoop()
{
    glutMainLoop();
}
