#include "jsApplication.h"

using namespace junseob;

namespace junseob
{
	Application::Application()
		: mHwnd(nullptr),
		mHdc(nullptr),
		mSpeed(0.0f),
		mX(0.0f),
		mY(0.0f)
	{

	}

	Application::~Application()
	{

	}

	void Application::Initialize(HWND hwnd)
	{
		mHwnd = hwnd;
		mHdc = GetDC(hwnd);
	}

	void Application::Run()
	{
		Update();
		LateUpdate();
		Render();
	}

	void Application::Update()
	{
		mSpeed += 0.01f;

		if (GetAsyncKeyState(VK_LEFT) & 0x8000)
		{
			mX -= 0.01f;
		}
		if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
		{
			mX += 0.01f;
		}
		if (GetAsyncKeyState(VK_UP) & 0x8000)
		{
			mY -= 0.01f;
		}
		if (GetAsyncKeyState(VK_DOWN) & 0x8000)
		{
			mY += 0.01f;
		}
	}

	void Application::LateUpdate()
	{

	}

	void Application::Render()
	{
		HBRUSH brush = CreateSolidBrush(RGB(255, 0, 0)); // 빨강 브러쉬 생성
		HBRUSH oldBrush = (HBRUSH)SelectObject(mHdc, brush); // 빨강 브러쉬 DC에 선택 그리고 반환된 기본 흰색 브러쉬 저장

		HPEN pen = CreatePen(PS_SOLID, 5, RGB(0, 0, 255)); // 파랑 펜 생성
		HPEN oldPen = (HPEN)SelectObject(mHdc, pen); // 파랑 펜 DC에 선택 그리고 반환된 기본 검은색 펜 저장

		Rectangle(mHdc, 100 + mX, 100 + mY, 200 + mX, 200 + mY); // (빨강 브러쉬와 파랑 펜으로) 사각형 그리기 

		SelectObject(mHdc, oldBrush); // 저장했던 기본 흰색 브러쉬 DC에 선택
		DeleteObject(brush); // 브러쉬 삭제

		SelectObject(mHdc, oldPen); // 저장했던 기본 검은색 펜 DC에 선택
		DeleteObject(pen); // 펜 삭제
	}
}
