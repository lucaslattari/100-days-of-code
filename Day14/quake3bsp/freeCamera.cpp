#include <stdio.h>
#include "freeCamera.h"

FreeCamera::FreeCamera()
{
    translation = vec3(0);
}

FreeCamera::~FreeCamera()
{

}

void FreeCamera::update()
{
    mat4 rotationObjectAxis = yawPitchRoll(yawRotationAngleYAxis, pitchRotationAngleXAxis, rollRotationAngleZAxis);

    position            += translation;
    //translation         = vec3(0);

    lookingAt           = vec3(rotationObjectAxis * vec4(0, 0, 1, 0));
    upCameraOnYAxis     = vec3(rotationObjectAxis * vec4(0, 1, 0, 0));
    rightCameraOnXAxis  = cross(lookingAt, upCameraOnYAxis);

    frontCameraOnZAxis  = position + lookingAt;
    viewMatrix          = lookAt(position, frontCameraOnZAxis, upCameraOnYAxis);
}

void FreeCamera::rotateCamera(float yaw, float pitch, float roll)
{
    yawRotationAngleYAxis   = yaw;
    pitchRotationAngleXAxis = pitch;
    rollRotationAngleZAxis  = roll;
}

void FreeCamera::walk(float amount)
{
    translation += lookingAt * amount;
    update();
}

void FreeCamera::strafe(float amount)
{
    translation += rightCameraOnXAxis * amount;
    update();
}

void FreeCamera::lift(float amount)
{
    translation += upCameraOnYAxis * amount;
    update();
}
