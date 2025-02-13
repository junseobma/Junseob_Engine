#include "jsTime.h"

namespace junseob
{
	LARGE_INTEGER Time::CpuFrequency = {}; // long 2개 붙인 8바이트
	LARGE_INTEGER Time::PrevFrequency = {};
	LARGE_INTEGER Time::CurrentFrequency = {};
	float Time::DeltaTimeValue = 0.0f; // 진동수를 시간으로 


	void Time::Initailize()
	{
		// CPU의 고유 진동수를 저장
		QueryPerformanceFrequency(&CpuFrequency);

		// 프로그램이 시작됐을 때 현재 진동 수 저장
		QueryPerformanceCounter(&PrevFrequency);
	}
	void Time::Update()
	{
		QueryPerformanceCounter(&CurrentFrequency);

		float differenceFrequency =
			static_cast<float>(CurrentFrequency.QuadPart - PrevFrequency.QuadPart); // QuadPart 8바이트 다 쓰기 위해서

		DeltaTimeValue = differenceFrequency / static_cast<float>(CpuFrequency.QuadPart); // 내 앞의 진동수 / 고유 진동수

		PrevFrequency.QuadPart = CurrentFrequency.QuadPart;
	}

	void Time::Render(HDC hdc)
	{
		//TCHAR str[100] = {};
		//swprintf_s(str, L"DeltaTimeValue : %f", DeltaTimeValue);
		//TextOut(hdc, 0, 0, str, wcslen(str));

		static float time = 0.0f;
		time += DeltaTimeValue;
		
		//wchar_t str[50] = L"";
		//swprintf_s(str, 50, L"Time: %f", time);
		////swprintf_s(str, 50, L"Time: %d", (int)time); // 정수형
		//int len = wcsnlen_s(str, 50);

		float fps = 1.0f / DeltaTimeValue; // 역수로 프레임을 구할 수 있다.
		wchar_t str[50] = L"";
		swprintf_s(str, 50, L"Time: %d", (int)fps);
		int len = wcsnlen_s(str, 50);


		TextOut(hdc, 0, 0, str, len);
	}

}