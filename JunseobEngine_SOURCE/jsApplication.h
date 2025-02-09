#pragma once
//#include "CommonInclude.h" //#pragma once�� �־ �������� ������
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

		// �÷��̾�
		//float mX;
		//float mY;
		GameObject mPlayer;
	};
}
