#include "jsApplication.h"
#include "jsInput.h"
#include "jsTime.h"

namespace junseob
{
	Application::Application()
		: mHwnd(nullptr)
		, mHdc(nullptr)
		, mWidth(0)
		, mHeight(0)
		, mBackHdc(nullptr)
		, mBackBitmap(nullptr)
	{

	}
	Application::~Application()
	{

	}

	void Application::Initialize(HWND hwnd, UINT width, UINT height)
	{
		mHwnd = hwnd;
		mHdc = GetDC(hwnd);

		RECT rect = {0, 0, width, height};
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

		mWidth = rect.right - rect.left;
		mHeight = rect.bottom - rect.top;

		SetWindowPos(mHwnd, nullptr, 0, 0, rect.right - rect.left, rect.bottom - rect.top, 0);
		ShowWindow(mHwnd, true);

		// �������� DC�� ������ �ػ󵵸� ������ �����(��Ʈ��) ����
		mBackBitmap = CreateCompatibleBitmap(mHdc, width, height);
		
		// ����۸� �������� ������ DC(�޸� DC) ����
		mBackHdc = CreateCompatibleDC(mHdc);

		// ������ ����� ��Ʈ���� �޸� DC�� �����ϰ�, ������ ����� ��Ʈ�� ��ȯ �� ���� ��Ʈ�� ������ �޸� ����
		HBITMAP oldBitmap = (HBITMAP)SelectObject(mBackHdc, mBackBitmap);
		DeleteObject(oldBitmap);

		mPlayer.SetPosition(0, 0);

		Input::Initailize();
		Time::Initailize();
	}

	void Application::Run()
	{
		Update();
		LateUpdate();
		Render();
	}

	void Application::Update()
	{
		Input::Update();
		Time::Update();
		
		mPlayer.Update();
	}

	void Application::LateUpdate()
	{

	}

	void Application::Render()
	{
		// �����(�޸� DC)�� ��� �簢������ �ʱ�ȭ, ȭ�� ����� ����
		Rectangle(mBackHdc, 0, 0, 1600, 900);

		// �ð� ���� ������
		Time::Render(mBackHdc);

		// �÷��̾� ������Ʈ ������
		mPlayer.Render(mBackHdc);

		// ������� ������ ���� ȭ�� DC(���� ����)�� �����Ͽ� ���, ���� ���۸�
		BitBlt(mHdc, 0, 0, mWidth, mHeight, mBackHdc, 0, 0, SRCCOPY);
	}
}
