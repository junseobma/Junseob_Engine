#include "jsInput.h"

namespace junseob
{
	std::vector<Input::Key> Input::Keys = {}; // 전역변수니까 전역영역에 초기화해줘야 된다.

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
		////모든 키에 대해 검사
		//for (size_t i = 0; i < Keys.size(); i++)
		//{
		//	// 키가 눌렸는지
		//	if (GetAsyncKeyState(ASCII[i]) & 0x8000)
		//	{
		//		if (Keys[i].bPressed == true)
		//			Keys[i].state = eKeyState::Pressed; // 키가 눌렸고 이전 프레임에 눌려져 있었다. 
		//		else
		//			Keys[i].state = eKeyState::Down; // 키가 눌렸고 이전 프레임도 지금도 눌러져 있지 않았다.
		//		Keys[i].bPressed = true;
		//	}
		//	else // 키가 안눌렸는지
		//	{
		//		if (Keys[i].bPressed == true)
		//			Keys[i].state = eKeyState::Up; // 키가 안눌렸고 이전 프레임에 눌려져 있었다.
		//		else
		//			Keys[i].state = eKeyState::None; // 키가 안눌렸고 이전 프레임도 눌러져 있지 않았다.
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
			key.state = eKeyState::Pressed; // 키가 눌렸고 이전 프레임에 눌려져 있었다. 
		else
			key.state = eKeyState::Down; // 키가 눌렸고 이전 프레임도 지금도 눌러져 있지 않았다.

		key.bPressed = true;
	}

	void Input::updateKeyUp(Input::Key& key)
	{
		if (key.bPressed == true)
			key.state = eKeyState::Up; // 키가 안눌렸고 이전 프레임에 눌려져 있었다.
		else
			key.state = eKeyState::None; // 키가 안눌렸고 이전 프레임도 눌러져 있지 않았다.

		key.bPressed = false;
	}

}
