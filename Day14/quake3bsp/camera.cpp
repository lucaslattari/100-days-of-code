#include <stdio.h>
#include "camera.h"

AbstractCamera::AbstractCamera()
{
    upCameraOnYAxis = vec3(0, 1, 0);
}

AbstractCamera::~AbstractCamera()
{
}

void AbstractCamera::setupProjection(float fovy, float aspectRatio, float zNear, float zFar)
{
    this->fieldOfView   = fovy;
    this->aspectRatio   = aspectRatio;
    this->zNear         = zNear;
    this->zFar          = zFar;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    projectionMatrix = perspective(radians(fovy), aspectRatio, zNear, zFar);
    glLoadMatrixf(&projectionMatrix[0][0]);

    glMatrixMode(GL_MODELVIEW);
}

mat4 AbstractCamera::getViewMatrix()
{
    return viewMatrix;
}

mat4 AbstractCamera::getProjectionMatrix()
{
    return projectionMatrix;
}

const vec3 AbstractCamera::getPosition()
{
    return position;
}

const vec3 AbstractCamera::getLookingAt()
{
    return lookingAt;
}

void AbstractCamera::setPosition(float posX, float posY, float posZ)
{
    position.x = posX;
    position.y = posY;
    position.z = posZ;
}

void AbstractCamera::setPosition(const vec3& v)
{
    position = v;
}

const float AbstractCamera::getFieldOfView()
{
    return fieldOfView;
}

const float AbstractCamera::getAspectRatio()
{
    return aspectRatio;
}

mat4 AbstractCamera::getMatrixUsingYawPitchRoll(float yaw, float pitch, float roll)
{
    mat4 r = mat4(1);

    r = rotate(r, roll, vec3(0, 0, 1));
    r = rotate(r, yaw, vec3(0, 1, 0));
    r = rotate(r, pitch, vec3(1, 0, 0));

    return r;
}
