#pragma once
//#include "CommonInclude.h" //#pragma once로 있어도 괜찮지만 지웠음
#include "jsGameObject.h"

namespace junseob
{
	class Application
	{
	public:
		Application();
		~Application();

		void Initialize(HWND hwnd, UINT width, UINT height);
		void Run();

		void Update();
		void LateUpdate();
		void Render();

	private:
		void clearRenderTarget();
		void copyRenderTarget(HDC source, HDC dest);

	private:
		HWND mHwnd;
		HDC mHdc;

		HDC mBackHdc;
		HBITMAP mBackBitmap;

		UINT mWidth;
		UINT mHeight;

		// 플레이어
		//float mX;
		//float mY;
		
		//GameObject mPlayer;
		std::vector<GameObject*> mGameObjects;
	};
}
