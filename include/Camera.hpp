/*
Abstract camera object, similar usage to glm::lookAt
Written by Patrick Gilfillan
*/

#ifndef CAMERA_H
#define CAMERA_H

class Camera {

public:
    Camera(float fov = glm::radians(45.0f), 
            float aspect = 4.0f / 3.0f, 
            float nearPlaneDistance = 0.1f, 
            float farPlaneDistance = 100.0f, 
            const glm::vec3& pos = glm::vec3(10, 10, 10), 
            const glm::vec3& lookAtPoint = glm::vec3(0, 0, 0), 
            const glm::vec3& upVec = glm::vec3(0, 1, 0));
    void setPos(const glm::vec3& newPos);
    const glm::vec3& getPos() {return pos_;}
    void lookAt(const glm::vec3& newPos, const glm::vec3& lookAtPoint, const glm::vec3& upVec);
    void lookAt(const glm::vec3& lookAtPoint, const glm::vec3& upVec);
    void lookAt(const glm::vec3& lookAtPoint);
    const glm::mat4& getProjection() {return projection_;}
    const glm::mat4& getView() {return view_;}

private:
    float fov_;
    float aspect_;
    float nearPlaneDistance_;
    float farPlaneDistance_;
    glm::vec3 pos_;
    glm::vec3 lookAtPoint_;
    glm::vec3 upVec_;

    glm::mat4 projection_;
    glm::mat4 view_;
};

#endif