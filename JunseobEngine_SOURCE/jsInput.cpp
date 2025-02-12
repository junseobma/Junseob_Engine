#include "jsInput.h"

namespace junseob
{
	std::vector<Input::Key> Input::mKeys = {}; // ���������ϱ� ���������� �ʱ�ȭ����� �ȴ�.

	int ASCII[(int)eKeyCode::End] = 
	{
		'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P',
		'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L',
		'Z', 'X', 'C', 'V', 'B', 'N', 'M',
		VK_LEFT, VK_RIGHT, VK_DOWN, VK_UP,
	};


	void Input::Initailize()
	{
		for (size_t i = 0; i < (UINT)eKeyCode::End; i++)
		{
			Key key = {};
			key.bPressed = false;
			key.state = eKeyState::None;
			key.keyCode = (eKeyCode)i;

			mKeys.push_back(key);
		}
	}

	void Input::Update()
	{
		//��� Ű�� ���� �˻�
		for (size_t i = 0; i < mKeys.size(); i++)
		{
			// Ű�� ���ȴ���
			if (GetAsyncKeyState(ASCII[i]) & 0x8000) 
			{
				if (mKeys[i].bPressed == true)
					mKeys[i].state = eKeyState::Pressed; // Ű�� ���Ȱ� ���� �����ӿ� ������ �־���. 
				else 
					mKeys[i].state = eKeyState::Down; // Ű�� ���Ȱ� ���� �����ӵ� ���ݵ� ������ ���� �ʾҴ�.

				mKeys[i].bPressed = true;
			}
			else // Ű�� �ȴ��ȴ���
			{
				if (mKeys[i].bPressed == true) 
					mKeys[i].state = eKeyState::Up; // Ű�� �ȴ��Ȱ� ���� �����ӿ� ������ �־���.
				else 
					mKeys[i].state = eKeyState::None; // Ű�� �ȴ��Ȱ� ���� �����ӵ� ������ ���� �ʾҴ�.

				mKeys[i].bPressed = false;
			}

		}
	}

}
