#include "jsInput.h"

namespace junseob
{
	std::vector<Input::Key> Input::Keys = {}; // ���������ϱ� ���������� �ʱ�ȭ����� �ȴ�.

	int ASCII[(int)eKeyCode::End] =
	{
		'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P',
		'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L',
		'Z', 'X', 'C', 'V', 'B', 'N', 'M',
		VK_LEFT, VK_RIGHT, VK_DOWN, VK_UP,
	};

	void Input::Initailize()
	{
		createKeys();
	}

	void Input::Update()
	{
		updateKeys();
	}

	void Input::createKeys()
	{
		for (size_t i = 0; i < (UINT)eKeyCode::End; i++)
		{
			Key key = {};
			key.bPressed = false;
			key.state = eKeyState::None;
			key.keyCode = (eKeyCode)i;

			Keys.push_back(key);
		}
	}

	void Input::updateKeys()
	{
		////��� Ű�� ���� �˻�
		//for (size_t i = 0; i < Keys.size(); i++)
		//{
		//	// Ű�� ���ȴ���
		//	if (GetAsyncKeyState(ASCII[i]) & 0x8000)
		//	{
		//		if (Keys[i].bPressed == true)
		//			Keys[i].state = eKeyState::Pressed; // Ű�� ���Ȱ� ���� �����ӿ� ������ �־���. 
		//		else
		//			Keys[i].state = eKeyState::Down; // Ű�� ���Ȱ� ���� �����ӵ� ���ݵ� ������ ���� �ʾҴ�.
		//		Keys[i].bPressed = true;
		//	}
		//	else // Ű�� �ȴ��ȴ���
		//	{
		//		if (Keys[i].bPressed == true)
		//			Keys[i].state = eKeyState::Up; // Ű�� �ȴ��Ȱ� ���� �����ӿ� ������ �־���.
		//		else
		//			Keys[i].state = eKeyState::None; // Ű�� �ȴ��Ȱ� ���� �����ӵ� ������ ���� �ʾҴ�.
		//		Keys[i].bPressed = false;
		//	}
		//}

		std::for_each(Keys.begin(), Keys.end(),
			[](Key& key) -> void
			{
				updateKey(key);
			});
	}

	void Input::updateKey(Input::Key& key)
	{
		if (isKeyDown(key.keyCode))
		{
			updateKeyDown(key);
		}
		else
		{
			updateKeyUp(key);
		}
	}

	bool Input::isKeyDown(eKeyCode code)
	{
		return GetAsyncKeyState(ASCII[(UINT)code]) & 0x8000;
	}

	void Input::updateKeyDown(Input::Key& key)
	{
		if (key.bPressed == true)
			key.state = eKeyState::Pressed; // Ű�� ���Ȱ� ���� �����ӿ� ������ �־���. 
		else
			key.state = eKeyState::Down; // Ű�� ���Ȱ� ���� �����ӵ� ���ݵ� ������ ���� �ʾҴ�.

		key.bPressed = true;
	}

	void Input::updateKeyUp(Input::Key& key)
	{
		if (key.bPressed == true)
			key.state = eKeyState::Up; // Ű�� �ȴ��Ȱ� ���� �����ӿ� ������ �־���.
		else
			key.state = eKeyState::None; // Ű�� �ȴ��Ȱ� ���� �����ӵ� ������ ���� �ʾҴ�.

		key.bPressed = false;
	}

}
