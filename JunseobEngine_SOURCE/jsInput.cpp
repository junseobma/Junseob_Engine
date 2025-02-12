#include "jsInput.h"

namespace junseob
{
	std::vector<Input::Key> Input::mKeys = {}; // 전역변수니까 전역영역에 초기화해줘야 된다.

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
		//모든 키에 대해 검사
		for (size_t i = 0; i < mKeys.size(); i++)
		{
			// 키가 눌렸는지
			if (GetAsyncKeyState(ASCII[i]) & 0x8000) 
			{
				if (mKeys[i].bPressed == true)
					mKeys[i].state = eKeyState::Pressed; // 키가 눌렸고 이전 프레임에 눌려져 있었다. 
				else 
					mKeys[i].state = eKeyState::Down; // 키가 눌렸고 이전 프레임도 지금도 눌러져 있지 않았다.

				mKeys[i].bPressed = true;
			}
			else // 키가 안눌렸는지
			{
				if (mKeys[i].bPressed == true) 
					mKeys[i].state = eKeyState::Up; // 키가 안눌렸고 이전 프레임에 눌려져 있었다.
				else 
					mKeys[i].state = eKeyState::None; // 키가 안눌렸고 이전 프레임도 눌러져 있지 않았다.

				mKeys[i].bPressed = false;
			}

		}
	}

}
