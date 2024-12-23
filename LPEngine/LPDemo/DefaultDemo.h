#pragma once
#include "BaseWindow.h"

#include <memory>
#include <LPCommon.h>

/// <summary>
/// 2024.12.23 Yujin
/// 데모를 분리하고 싶을 때 이 클래스를 복사해서 사용하면 된다. 
/// 상속을 할까
/// </summary>

class TimeManager;
class InputManager;

class DefaultDemo : public BaseWindow<DefaultDemo>
{
public:
	DefaultDemo();
	~DefaultDemo();

	bool Init(HINSTANCE hInstance);
	void Loop();
	void Finalize();

	LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam) override;

private:
	// Default Framework
	void Update();
	void Render();
	void DebugRender();

private:
	PCWSTR mDemoWindowName;

	/// 기본적으로 필요한 변수들 
	const int mWindowPosX;
	const int mWindowPosY;

	int mScreenWidth;
	int mScreenHeight;

	bool mResizing;

	/// Demo Control
	TimeManager* mTimeManager;
	InputManager* mInputManager;

	lp::common::Transform mCameraTransform;

	/// Graphics
	// Engine
	//fq::graphics::IFQGraphics* mTestGraphics;
	//std::shared_ptr<fq::graphics::EngineExporter> mEngineExporter;
};

