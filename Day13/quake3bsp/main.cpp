#include "bsp.h"
#include "window.h"

void startScreen()
{
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0f, 1.0f, 0.0f, 1.0f, -1.0f, 1.0f);
}

void drawAxis()
{
    glBegin(GL_LINES);
    glColor3f(1.0f, 0.0f, 0.0f); //x axis
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(100.0f, 0.0f, 0.0f);

    glColor3f(0.0f, 1.0f, 0.0f); //y axis
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 100.0f, 0.0f);

    glColor3f(0.0f, 0.0f, 1.0f);//z axis
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, 100.0f);
    glEnd();
}

void renderScene()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    drawAxis();

    glutSwapBuffers();
}

void duringWindowReshape(int width, int height)
{
    if(height == 0)
        height = 1;

    glViewport(0, 0, width, height);
}

int main(int argc, char** argv)
{
    BSP     bsp("final.bsp");
    Window  window;

    startScreen();

    window.setWindowPosition(0, 0);
    window.setWindowSize(1024, 768);
    window.createWindow("CEREBRO 3D ENGINE");
    window.calledWhenWindowIsRedrawed(renderScene);
    window.calledWhenWindowIsReshaped(duringWindowReshape);

    window.repeatLoop();
}
