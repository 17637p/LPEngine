#include "DefaultDemo.h"

#include "TimeManager.h"
#include "InputManager.h"

#include "DemoUtils.h"

using namespace lp::utils;

DefaultDemo::DefaultDemo()
	:mDemoWindowName(L"LP_Default_Demo")
	, mWindowPosX(0)
	, mWindowPosY(0)
	, mScreenWidth(1920)
	, mScreenHeight(1080)
	, mResizing(false)
	, mTimeManager(nullptr)
	, mInputManager(nullptr)
	, mCameraTransform()
{
	HRESULT hr = CoInitializeEx(nullptr, COINIT_APARTMENTTHREADED);

	CreateHWND(mDemoWindowName, WS_OVERLAPPEDWINDOW, mWindowPosX, mWindowPosY, mScreenWidth, mScreenHeight);
	ShowWindow(mHwnd, SW_SHOWNORMAL);

	//mEngineExporter = std::make_shared<fq::graphics::EngineExporter>();
}

DefaultDemo::~DefaultDemo()
{
	//mEngineExporter->DeleteEngine(mTestGraphics);

	CoUninitialize();
}

bool DefaultDemo::Init(HINSTANCE hInstance)
{
	mTimeManager = new TimeManager;
	mInputManager = new InputManager;

	return true;
}

void DefaultDemo::Loop()
{
	MSG msg;

	while (true)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
			{
				break;
			}

			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			Update();
			Render();
		}
	}
}

void DefaultDemo::Finalize()
{
	delete mInputManager;
	delete mTimeManager;
}

LRESULT DefaultDemo::HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	HDC			hdc;
	PAINTSTRUCT ps;

	//if (ImGui_ImplWin32_WndProcHandler(m_hWnd, uMsg, wParam, lParam))
	//	return true;

	switch (uMsg)
	{
		case WM_SIZE:
		{
			mScreenWidth = LOWORD(lParam);
			mScreenHeight = HIWORD(lParam);
			mScreenWidth = max(200, mScreenWidth);
			mScreenHeight = max(200, mScreenHeight);

			break;
		}
		case WM_PAINT:
		{
			hdc = BeginPaint(mHwnd, &ps);
			EndPaint(mHwnd, &ps);
			break;
		}
		case WM_DESTROY:
		{
			PostQuitMessage(0);
			break;
		}
	}

	return DefWindowProc(mHwnd, uMsg, wParam, lParam);
}

void DefaultDemo::Update()
{
	mTimeManager->Update();
	mInputManager->Update();

	// ESC 버튼 누르면 프로그램 종료
	if (GetAsyncKeyState(VK_ESCAPE))
	{
		PostQuitMessage(0);
	}

	// 카메라 조작
	float speed = mTimeManager->GetDeltaTime();
	if (mInputManager->IsGetKey(VK_SHIFT))
	{
		speed = mTimeManager->GetDeltaTime() * 10;
	}
	else
	{
		speed = mTimeManager->GetDeltaTime();
	}

	if (mInputManager->IsGetKey('W'))
	{
		Walk(mCameraTransform, speed);
	}
	if (mInputManager->IsGetKey('S'))
	{
		Walk(mCameraTransform, -speed);
	}
	if (mInputManager->IsGetKey('D'))
	{
		Strafe(mCameraTransform, speed);
	}
	if (mInputManager->IsGetKey('A'))
	{
		Strafe(mCameraTransform, -speed);
	}
	if (mInputManager->IsGetKey('E'))
	{
		WorldUpdown(mCameraTransform, speed);
	}
	if (mInputManager->IsGetKey('Q'))
	{
		WorldUpdown(mCameraTransform, -speed);
	}

	if (mInputManager->IsGetKey(VK_RBUTTON))
	{
		float dx = (0.25f * static_cast<float>(mInputManager->GetDeltaPosition().x) * (3.141592f / 180.0f));
		float dy = (0.25f * static_cast<float>(mInputManager->GetDeltaPosition().y) * (3.141592f / 180.0f));

		Pitch(mCameraTransform, dy);
		Yaw(mCameraTransform, dx);
	}
}

void DefaultDemo::Render()
{
	// Call Engine Render 
}

void DefaultDemo::DebugRender()
{
	// 그리드, 축 그리는 기능 추가 
}
