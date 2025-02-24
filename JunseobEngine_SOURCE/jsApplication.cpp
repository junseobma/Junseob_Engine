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
		, mGameObjects{}
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

		Input::Initailize();
		Time::Initailize();

		for (size_t i = 0; i < 100; i++)
		{
			GameObject* gameObj = new GameObject();

			gameObj->SetPosition(rand() % 1600, rand() % 900);
			mGameObjects.push_back(gameObj);
		}
		
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
		
		//mPlayer.Update();
		for (size_t i = 0; i < mGameObjects.size(); i++)
		{
			mGameObjects[i]->Update();
		}

	}

	void Application::LateUpdate()
	{

	}

	void Application::Render()
	{
		clearRenderTarget();

		Time::Render(mBackHdc); // �ð� ���� ������
		
		//mPlayer.Render(mBackHdc); // �÷��̾� ������Ʈ ������
		for (size_t i = 0; i < mGameObjects.size(); i++)
		{
			mGameObjects[i]->Render(mBackHdc);
		}

		copyRenderTarget(mBackHdc, mHdc);
	}

	// �����(�޸� DC)�� ��� �簢������ �ʱ�ȭ, ȭ�� ����� ����
	void  Application::clearRenderTarget()
	{
		//Rectangle(mBackHdc, 0, 0, 1600, 900);
		Rectangle(mBackHdc, -1, -1, 1601, 901); //ȭ���� ���� ä��� ���ؼ�
	}

	// ������� ������ ���� ȭ�� DC(���� ����)�� �����Ͽ� ���, ���� ���۸�
	void Application::copyRenderTarget(HDC source, HDC dest)
	{
		BitBlt(dest, 0, 0, mWidth, mHeight, source, 0, 0, SRCCOPY);
	}


}
