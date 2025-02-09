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
		HBRUSH brush = CreateSolidBrush(RGB(255, 0, 0)); // ���� �귯�� ����
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, brush); // ���� �귯�� DC�� ���� �׸��� ��ȯ�� �⺻ ��� �귯�� ����

		HPEN pen = CreatePen(PS_SOLID, 5, RGB(0, 0, 255)); // �Ķ� �� ����
		HPEN oldPen = (HPEN)SelectObject(hdc, pen); // �Ķ� �� DC�� ���� �׸��� ��ȯ�� �⺻ ������ �� ����

		//float x = mPlayer.GetPositionX();
		//float y = mPlayer.GetPositionY();
		//Rectangle(hdc, 100 + x, 100 + y, 200 + x, 200 + y); // (���� �귯���� �Ķ� ������) �簢�� �׸��� 
		Rectangle(hdc, 100 + mX, 100 + mY, 200 + mX, 200 + mY); // (���� �귯���� �Ķ� ������) �簢�� �׸��� 

		SelectObject(hdc, oldBrush); // �����ߴ� �⺻ ��� �귯�� DC�� ����
		DeleteObject(brush); // �귯�� ����

		SelectObject(hdc, oldPen); // �����ߴ� �⺻ ������ �� DC�� ����
		DeleteObject(pen); // �� ����
	}

}
