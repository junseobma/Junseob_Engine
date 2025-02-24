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

		// 윈도우의 DC와 동일한 해상도를 가지는 백버퍼(비트맵) 생성
		mBackBitmap = CreateCompatibleBitmap(mHdc, width, height);
		
		// 백버퍼를 렌더링할 별도의 DC(메모리 DC) 생성
		mBackHdc = CreateCompatibleDC(mHdc);

		// 생성한 백버퍼 비트맵을 메모리 DC에 연결하고, 이전에 연결된 비트맵 반환 후 사용된 비트맵 삭제해 메모리 정리
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

		Time::Render(mBackHdc); // 시간 관련 렌더링
		
		//mPlayer.Render(mBackHdc); // 플레이어 오브젝트 렌더링
		for (size_t i = 0; i < mGameObjects.size(); i++)
		{
			mGameObjects[i]->Render(mBackHdc);
		}

		copyRenderTarget(mBackHdc, mHdc);
	}

	// 백버퍼(메모리 DC)를 흰색 사각형으로 초기화, 화면 지우기 역할
	void  Application::clearRenderTarget()
	{
		//Rectangle(mBackHdc, 0, 0, 1600, 900);
		Rectangle(mBackHdc, -1, -1, 1601, 901); //화면을 가득 채우기 위해서
	}

	// 백버퍼의 내용을 실제 화면 DC(원본 버퍼)로 복사하여 출력, 더블 버퍼링
	void Application::copyRenderTarget(HDC source, HDC dest)
	{
		BitBlt(dest, 0, 0, mWidth, mHeight, source, 0, 0, SRCCOPY);
	}


}
