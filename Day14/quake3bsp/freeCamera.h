#ifndef _FREECAMERA_H_
#define _FREECAMERA_H_

#include "camera.h"

class FreeCamera : public AbstractCamera
{
private:
    float speed;

    vec3  translation;
public:
    FreeCamera(void);
    ~FreeCamera(void);

    void update();
    void rotateCamera(float yaw, float pitch, float roll);

    void walk(const float dt);
    void strafe(const float dt);
    void lift(const float dt);

    void setTranslation(const vec3& t);
    vec3 getTranslation() const;
    void setSpeed(const float speed);
    const float getSpeed() const;
};

#endif // _FREECAMERA_H_
