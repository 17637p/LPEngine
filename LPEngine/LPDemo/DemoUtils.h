#pragma once

#include <LPCommon.h>

namespace lp::utils
{
	/*=============================================================================
								Camera Moving
	=============================================================================*/
#pragma region camera
	void Strafe(lp::common::Transform& cameraTransform, float distance);
	void Walk(lp::common::Transform& cameraTransform, float distance);
	void WorldUpdown(lp::common::Transform& cameraTransform, float distance);

	void Yaw(lp::common::Transform& cameraTransform, float angle);
	void Pitch(lp::common::Transform& cameraTransform, float angle);
#pragma endregion camera

	//void AddDefaultCamera(lp::graphics::IFQGraphics* graphcis);
	//void AddLittleNearCamera(lp::graphics::IFQGraphics* graphcis);
	//void AddDefaultLight();
}

