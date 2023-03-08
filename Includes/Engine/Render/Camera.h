//
// Created by No on 2023-03-04.
//

#ifndef MINA_CAMERA_H
#define MINA_CAMERA_H

#include "pch.hpp"

namespace Mina
{

struct ViewParams {
	glm::vec3 eye{0, 0, 100};
	glm::vec3 at{0, 0, 0};
	glm::vec3 up{0, 1, 0};
};

struct ProjectionParams {
	float zoom{45.0f};
	float aspect{1.0f};
	float zNear{1.0f};
	float zFar{5e3f};
};

class Camera
{
private:
	ViewParams viewParams;
	ProjectionParams projectionParams{};

	glm::mat4 projection{};
	glm::mat4 view{};

public:
	 explicit Camera(const ViewParams& viewParams, const ProjectionParams& projectionParams = ProjectionParams());
	~Camera();

	[[nodiscard]] const ViewParams& getViewParams() const;
	[[nodiscard]] const ProjectionParams& getProjectionParams() const;

	[[nodiscard]] const glm::mat4& getViewMatrix() const;
	[[nodiscard]] const glm::mat4& getProjMatrix() const;

	void updateView();
	void updateProjection();

	void setAspectRatio(float aspectRatio);
};

}	 // namespace Mina

#endif	  // MINA_CAMERA_H
