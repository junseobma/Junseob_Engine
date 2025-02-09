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

		void Initialize(HWND hwnd);
		void Run();

		void Update();
		void LateUpdate();
		void Render();

	private:
		HWND mHwnd;
		HDC mHdc;

		// 플레이어
		//float mX;
		//float mY;
		GameObject mPlayer;
	};
}
