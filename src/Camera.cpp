/*
Implementation of Camera.hpp
Written by Patrick Gilfillan
*/

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "Camera.hpp"

Camera::Camera(float fov, float aspect, float nearPlaneDistance, float farPlaneDistance, const glm::vec3& pos, 
        const glm::vec3& lookAtPoint, const glm::vec3& upVec):
        fov_(fov), aspect_(aspect), nearPlaneDistance_(nearPlaneDistance), farPlaneDistance_(farPlaneDistance),
        pos_(pos), lookAtPoint_(lookAtPoint), upVec_(upVec)
{
    projection_ = glm::perspective(fov, aspect, nearPlaneDistance, farPlaneDistance);
    view_ = glm::lookAt(pos, lookAtPoint, upVec);
}

void Camera::lookAt(const glm::vec3& newPos, const glm::vec3& lookAtPoint, const glm::vec3& upVec) {
    pos_ = newPos;
    lookAtPoint_ = lookAtPoint;
    upVec_ = upVec;
    view_ = glm::lookAt(pos_, lookAtPoint_, upVec_);
}

void Camera::lookAt(const glm::vec3& lookAtPoint, const glm::vec3& upVec) {
    lookAtPoint_ = lookAtPoint;
    upVec_ = upVec;
    view_ = glm::lookAt(pos_, lookAtPoint_, upVec_);
}

void Camera::lookAt(const glm::vec3& lookAtPoint) {
    lookAtPoint_ = lookAtPoint;
    view_ = glm::lookAt(pos_, lookAtPoint_, upVec_);
}