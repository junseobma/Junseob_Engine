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
		HBRUSH brush = CreateSolidBrush(RGB(255, 0, 0)); // ���� �귯�� ����
		HBRUSH oldBrush = (HBRUSH)SelectObject(mHdc, brush); // ���� �귯�� DC�� ���� �׸��� ��ȯ�� �⺻ ��� �귯�� ����

		HPEN pen = CreatePen(PS_SOLID, 5, RGB(0, 0, 255)); // �Ķ� �� ����
		HPEN oldPen = (HPEN)SelectObject(mHdc, pen); // �Ķ� �� DC�� ���� �׸��� ��ȯ�� �⺻ ������ �� ����

		Rectangle(mHdc, 100 + mX, 100 + mY, 200 + mX, 200 + mY); // (���� �귯���� �Ķ� ������) �簢�� �׸��� 

		SelectObject(mHdc, oldBrush); // �����ߴ� �⺻ ��� �귯�� DC�� ����
		DeleteObject(brush); // �귯�� ����

		SelectObject(mHdc, oldPen); // �����ߴ� �⺻ ������ �� DC�� ����
		DeleteObject(pen); // �� ����
	}
}
