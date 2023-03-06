//
// Created by No on 2023-03-04.
//
#include "Render/Camera.h"

namespace Mina
{

Camera::Camera(const ViewParams& viewParams, const ProjectionParams& projectionParams)
	: viewParams(viewParams), projectionParams(projectionParams)
{
	updateView();
	updateProjection();
}

Camera::~Camera() = default;


const glm::mat4& Camera::getViewMatrix() const
{
	return view;
}

const glm::mat4& Camera::getProjMatrix() const
{
	return projection;
}

const ViewParams& Camera::getViewParams() const
{
	return viewParams;
}

const ProjectionParams& Camera::getProjectionParams() const
{
	return projectionParams;
}

void Camera::updateView()
{
	view = glm::lookAt(viewParams.eye, viewParams.at, viewParams.up);
}

void Camera::updateProjection()
{
	projection = glm::perspective(projectionParams.zoom, projectionParams.aspect, projectionParams.zNear, projectionParams.zFar);
}

void Camera::setAspectRatio(float aspectRatio)
{
	projectionParams.aspect = aspectRatio;
	updateProjection();
}

}	 // namespace Mina
