#include "jsTime.h"

namespace junseob
{
	LARGE_INTEGER Time::CpuFrequency = {}; // long 2�� ���� 8����Ʈ
	LARGE_INTEGER Time::PrevFrequency = {};
	LARGE_INTEGER Time::CurrentFrequency = {};
	float Time::DeltaTimeValue = 0.0f; // �������� �ð����� 


	void Time::Initailize()
	{
		// CPU�� ���� �������� ����
		QueryPerformanceFrequency(&CpuFrequency);

		// ���α׷��� ���۵��� �� ���� ���� �� ����
		QueryPerformanceCounter(&PrevFrequency);
	}
	void Time::Update()
	{
		QueryPerformanceCounter(&CurrentFrequency);

		float differenceFrequency =
			static_cast<float>(CurrentFrequency.QuadPart - PrevFrequency.QuadPart); // QuadPart 8����Ʈ �� ���� ���ؼ�

		DeltaTimeValue = differenceFrequency / static_cast<float>(CpuFrequency.QuadPart); // �� ���� ������ / ���� ������

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
		////swprintf_s(str, 50, L"Time: %d", (int)time); // ������
		//int len = wcsnlen_s(str, 50);

		float fps = 1.0f / DeltaTimeValue; // ������ �������� ���� �� �ִ�.
		wchar_t str[50] = L"";
		swprintf_s(str, 50, L"Time: %d", (int)fps);
		int len = wcsnlen_s(str, 50);


		TextOut(hdc, 0, 0, str, len);
	}

}