#ifndef _CAMERA_H_
#define _CAMERA_H_

#include <vector>
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/euler_angles.hpp>

using namespace glm;

class AbstractCamera
{
protected:
    mat4    viewMatrix;
    mat4    projectionMatrix;

    vec3    position;
    vec3    lookingAt;
    vec3    upCameraOnYAxis;
    vec3    frontCameraOnZAxis;
    vec3    rightCameraOnXAxis;

    float   yawRotationAngleYAxis, pitchRotationAngleXAxis, rollRotationAngleZAxis, fieldOfView, aspectRatio, zNear, zFar;

    //GLfloat movementSpeed;
    //GLfloat mouseSensitivity;
    //GLfloat zoom;

public:
    AbstractCamera(void);
    ~AbstractCamera(void);

    void            setupProjection(float fovy = 45.0f, float aspectRatio = 1.333333f, float zNear = 0.1f, float zFar = 1000.0f);

    virtual void    update() = 0;
    virtual void    rotateCamera(float yaw, float pitch, float roll) = 0;

    void            printCameraData();
    void            printViewMatrix();
    void            printProjectionMatrix();

    mat4            getViewMatrix();
    mat4            getProjectionMatrix();

    void            setPosition(float posX, float posY, float posZ);
    void            setPosition(const vec3& v);
    const vec3      getPosition();
    const vec3      getLookingAt();

    void            setFieldOfView(const float fov);
    const float     getFieldOfView();
    const float     getAspectRatio();

    mat4            getMatrixUsingYawPitchRoll(const float yaw, const float pitch, const float roll);

    //void            computeFrustumPlanes();

    bool            isPointInFrustrum(const vec3& point);
    bool            isSphereInFrustrum(const vec3& center, const float radius);
    bool            isBoxInFrustrum(const vec3& minimumCoord, const vec3& maximumCoord);

    //void            updateViewMatrix();
};

#endif // _CAMERA_H_
