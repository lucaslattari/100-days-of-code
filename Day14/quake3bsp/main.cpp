#define GLEW_STATIC
#define _USE_MATH_DEFINES

#define M_PI 3.14

#include <glm/gtc/type_ptr.hpp>

#include "GLSLShader.h"
#include "simpleTriangle.h"
#include "bsp.h"
#include "window.h"
#include "freeCamera.h"

#define GL_CHECK_ERRORS assert(glGetError()== GL_NO_ERROR);

GLSLShader shader;

using namespace glm;

Window          window;
const int       width   = 1280;
const int       height  = 960;

int oldX = 0, oldY = 0, mouseState = 0;
float rX = 0, rY = 0, fov = 45;

enum mouseStateEnum{ZOOM_STATE = 0, ROTATE_STATE};

//virtual key codes
const int KEY_W = 0x57;
const int KEY_S = 0x53;
const int KEY_A = 0x41;
const int KEY_D = 0x44;
const int KEY_Q = 0x51;
const int KEY_Z = 0x5a;

//delta time
float dt = 0;

//timing related variables
float lastTime = 0, currentTime = 0;

//free camera instance
FreeCamera camera;
unsigned int vertexShader = 0;
unsigned int fragmentShader = 0;
unsigned int program = 0;

void onMouseDown(int button, int state, int x, int y)
{
    if(state == GLUT_DOWN)
    {
        oldX = x;
        oldY = y;
    }

    if(button == GLUT_MIDDLE_BUTTON)
        state = ZOOM_STATE;
    else
        state = ROTATE_STATE;

    /*if(button == GLUT_LEFT_BUTTON)
        printf("left button pressed\n");
    else if(button == GLUT_MIDDLE_BUTTON)
        printf("middle button pressed\n");
    else
        printf("right button pressed\n");

    if(state == GLUT_UP)
        printf("release button\n");
    else
        printf("pressed button\n");

    printf("position: %d %d\n", x, y);*/
}

void onMouseMove(int x, int y)
{
    if(mouseState == ZOOM_STATE)
    {
        fov += (y - oldY) / 5.0f;
        camera.setupProjection(fov, camera.getAspectRatio());
    }else
    {
        rY += (y - oldY) / 5.0f;
        rX += (oldX - x) / 5.0f;

        //mouseX = rX;
        //mouseY = rY;

        camera.rotateCamera(rX, rY, 0);
    }

    oldX = x;
    oldY = y;

    glutPostRedisplay();
    //glutSwapBuffers();
}

void onInit()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
    glClearDepth(1.0f);                   // Set background depth to farthest
    glEnable(GL_DEPTH_TEST);   // Enable depth testing for z-culling
    glDepthFunc(GL_LEQUAL);    // Set the type of depth-test
    glShadeModel(GL_SMOOTH);   // Enable smooth shading
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);  // Nice perspective corrections

    // here begins the shader setup:
    vertexShader    = glCreateShader(GL_VERTEX_SHADER);
    fragmentShader  = glCreateShader(GL_FRAGMENT_SHADER);
    program         = glCreateProgram();

    vec3 p = vec3(5);
    camera.setPosition(p);
    vec3 look = normalize(p);

    float yaw   = degrees(float(atan2(look.z, look.x) + M_PI));
    float pitch = degrees(sin(look.y));
    rX = yaw;
	rY = pitch;

	camera.rotateCamera(rX, rY, 0);
}

void onShutdown()
{
}

void onIdle()
{
    if(GetAsyncKeyState(KEY_W) & 0x8000)
        camera.walk(dt);
    if(GetAsyncKeyState(KEY_S) & 0x8000)
        camera.walk(-dt);
    if(GetAsyncKeyState(KEY_A) & 0x8000)
        camera.strafe(-dt);
    if(GetAsyncKeyState(KEY_D) & 0x8000)
        camera.strafe(dt);
    if(GetAsyncKeyState(KEY_Q) & 0x8000)
        camera.lift(dt);
    if(GetAsyncKeyState(KEY_Z) & 0x8000)
        camera.lift(-dt);

	//camera.update();
    glutPostRedisplay();
}

void onResize(int width, int height)
{
    /*if(height == 0)
        height = 1;

    GLfloat aspectRatio = (GLfloat)width / (GLfloat)height;*/
    glViewport(0, 0, (GLsizei)width, (GLsizei)height);
    camera.setupProjection(45.0f, (GLfloat)width / height);
}

void drawAxis()
{
    glLoadIdentity();

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

void drawColorCube()
{
    glLoadIdentity();
    glTranslatef(1.5f, 0.0f, -7.0f);  // Move right and into the screen

    glBegin(GL_QUADS);                // Begin drawing the color cube with 6 quads
      // Top face (y = 1.0f)
      // Define vertices in counter-clockwise (CCW) order with normal pointing out
      glColor3f(0.0f, 1.0f, 0.0f);     // Green
      glVertex3f( 1.0f, 1.0f, -1.0f);
      glVertex3f(-1.0f, 1.0f, -1.0f);
      glVertex3f(-1.0f, 1.0f,  1.0f);
      glVertex3f( 1.0f, 1.0f,  1.0f);

      // Bottom face (y = -1.0f)
      glColor3f(1.0f, 0.5f, 0.0f);     // Orange
      glVertex3f( 1.0f, -1.0f,  1.0f);
      glVertex3f(-1.0f, -1.0f,  1.0f);
      glVertex3f(-1.0f, -1.0f, -1.0f);
      glVertex3f( 1.0f, -1.0f, -1.0f);

      // Front face  (z = 1.0f)
      glColor3f(1.0f, 0.0f, 0.0f);     // Red
      glVertex3f( 1.0f,  1.0f, 1.0f);
      glVertex3f(-1.0f,  1.0f, 1.0f);
      glVertex3f(-1.0f, -1.0f, 1.0f);
      glVertex3f( 1.0f, -1.0f, 1.0f);

      // Back face (z = -1.0f)
      glColor3f(1.0f, 1.0f, 0.0f);     // Yellow
      glVertex3f( 1.0f, -1.0f, -1.0f);
      glVertex3f(-1.0f, -1.0f, -1.0f);
      glVertex3f(-1.0f,  1.0f, -1.0f);
      glVertex3f( 1.0f,  1.0f, -1.0f);

      // Left face (x = -1.0f)
      glColor3f(0.0f, 0.0f, 1.0f);     // Blue
      glVertex3f(-1.0f,  1.0f,  1.0f);
      glVertex3f(-1.0f,  1.0f, -1.0f);
      glVertex3f(-1.0f, -1.0f, -1.0f);
      glVertex3f(-1.0f, -1.0f,  1.0f);

      // Right face (x = 1.0f)
      glColor3f(1.0f, 0.0f, 1.0f);     // Magenta
      glVertex3f(1.0f,  1.0f, -1.0f);
      glVertex3f(1.0f,  1.0f,  1.0f);
      glVertex3f(1.0f, -1.0f,  1.0f);
      glVertex3f(1.0f, -1.0f, -1.0f);
   glEnd();  // End of drawing color-cube

    glPopMatrix();
}

void drawPyramid()
{
    glLoadIdentity();
    // Render a pyramid consists of 4 triangles
    glTranslatef(-0.5f, -1.0f, -6.0f);  // Move left and into the screen

    glBegin(GL_TRIANGLES);           // Begin drawing the pyramid with 4 triangles
      // Front
      glColor3f(1.0f, 0.0f, 0.0f);     // Red
      glVertex3f( 0.0f, 1.0f, 0.0f);
      glColor3f(0.0f, 1.0f, 0.0f);     // Green
      glVertex3f(-1.0f, -1.0f, 1.0f);
      glColor3f(0.0f, 0.0f, 1.0f);     // Blue
      glVertex3f(1.0f, -1.0f, 1.0f);

      // Right
      glColor3f(1.0f, 0.0f, 0.0f);     // Red
      glVertex3f(0.0f, 1.0f, 0.0f);
      glColor3f(0.0f, 0.0f, 1.0f);     // Blue
      glVertex3f(1.0f, -1.0f, 1.0f);
      glColor3f(0.0f, 1.0f, 0.0f);     // Green
      glVertex3f(1.0f, -1.0f, -1.0f);

      // Back
      glColor3f(1.0f, 0.0f, 0.0f);     // Red
      glVertex3f(0.0f, 1.0f, 0.0f);
      glColor3f(0.0f, 1.0f, 0.0f);     // Green
      glVertex3f(1.0f, -1.0f, -1.0f);
      glColor3f(0.0f, 0.0f, 1.0f);     // Blue
      glVertex3f(-1.0f, -1.0f, -1.0f);

      // Left
      glColor3f(1.0f,0.0f,0.0f);       // Red
      glVertex3f( 0.0f, 1.0f, 0.0f);
      glColor3f(0.0f,0.0f,1.0f);       // Blue
      glVertex3f(-1.0f,-1.0f,-1.0f);
      glColor3f(0.0f,1.0f,0.0f);       // Green
      glVertex3f(-1.0f,-1.0f, 1.0f);
   glEnd();   // Done drawing the pyramid
}

void onRender()
{
	//timing related calcualtion
	lastTime    = currentTime;
	currentTime = glutGet(GLUT_ELAPSED_TIME)/1000.0f;
	dt          = currentTime - lastTime;

	//clear color buffer and depth buffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear color and depth buffers
    glUseProgram(program);

    glMatrixMode(GL_MODELVIEW);

    static float angle = 0;

	glm::mat4 MV	= camera.getViewMatrix();
	glm::mat4 P     = camera.getProjectionMatrix();
    glm::mat4 MVP	= P * MV;

	shader.Use();
		glUniformMatrix4fv(shader("MVP"), 1, GL_FALSE, glm::value_ptr(MVP));
		//SetCustomUniforms();
		glBindVertexArray(1);
			//glDrawElements(primType, totalIndices, GL_UNSIGNED_INT, 0);
            drawAxis();
            drawColorCube();
		glBindVertexArray(0);
	shader.UnUse();

    //drawAxis();
    //drawPyramid();

    printf("position: %f %f %f\n", camera.getPosition().x, camera.getPosition().y, camera.getPosition().z);
    //printf("look at: %f %f %f\n", camera.getLookingAt().x, camera.getLookingAt().y, camera.getLookingAt().z);

	/*mat4 modelViewMatrix    = camera.getViewMatrix();
	mat4 projectionMatrix   = camera.getProjectionMatrix();
	mat4 mvp                = modelViewMatrix * projectionMatrix;

	glLoadMatrixf(value_ptr(mvp));*/

    glutSwapBuffers();
}

int main(int argc, char** argv)
{
    //BSP bsp("final.bsp");

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE);
    window.setWindowPosition(50, 50);
    window.setWindowSize(width, height);
    window.createWindow("CEREBRO 3D ENGINE 0.00000000000001");
    glewInit();

    onInit();
    window.calledWhenWindowIsRedrawed(onRender);
    window.calledWhenWindowIsReshaped(onResize);
    window.calledWhenMouseEventOccurs(onMouseDown);
    window.calledWhenMouseMoves(onMouseMove);
    window.calledWhenIdle(onIdle);
    glutCloseFunc(onShutdown);

    window.repeatLoop();

    return 0;
}
