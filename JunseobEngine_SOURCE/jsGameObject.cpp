#include "jsGameObject.h"

namespace junseob
{
	GameObject::GameObject()
	{

	}
	GameObject::~GameObject()
	{

	}

	void GameObject::Update()
	{
		//float x = mPlayer.GetPositionX();
		//float y = mPlayer.GetPositionY();
		//if (GetAsyncKeyState(VK_LEFT) & 0x8000)
		//{
		//	x -= 0.01f;
		//}
		//if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
		//{
		//	x += 0.01f;
		//}
		//if (GetAsyncKeyState(VK_UP) & 0x8000)
		//{
		//	y -= 0.01f;
		//}
		//if (GetAsyncKeyState(VK_DOWN) & 0x8000)
		//{
		//	y += 0.01f;
		//}
		//mPlayer.SetPosition(x, y);

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

	void GameObject::LateUpdate()
	{

	}

	void GameObject::Render(HDC hdc)
	{
		HBRUSH brush = CreateSolidBrush(RGB(255, 0, 0)); // 빨강 브러쉬 생성
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, brush); // 빨강 브러쉬 DC에 선택 그리고 반환된 기본 흰색 브러쉬 저장

		HPEN pen = CreatePen(PS_SOLID, 5, RGB(0, 0, 255)); // 파랑 펜 생성
		HPEN oldPen = (HPEN)SelectObject(hdc, pen); // 파랑 펜 DC에 선택 그리고 반환된 기본 검은색 펜 저장

		//float x = mPlayer.GetPositionX();
		//float y = mPlayer.GetPositionY();
		//Rectangle(hdc, 100 + x, 100 + y, 200 + x, 200 + y); // (빨강 브러쉬와 파랑 펜으로) 사각형 그리기 
		Rectangle(hdc, 100 + mX, 100 + mY, 200 + mX, 200 + mY); // (빨강 브러쉬와 파랑 펜으로) 사각형 그리기 

		SelectObject(hdc, oldBrush); // 저장했던 기본 흰색 브러쉬 DC에 선택
		DeleteObject(brush); // 브러쉬 삭제

		SelectObject(hdc, oldPen); // 저장했던 기본 검은색 펜 DC에 선택
		DeleteObject(pen); // 펜 삭제
	}

}
