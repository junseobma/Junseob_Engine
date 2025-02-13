#pragma once
#include <CommonInclude.h>

namespace junseob
{
	class Time
	{
	public:
		static void Initailize();
		static void Update();
		static void Render(HDC hdc);

		static float DeltaTime() { return DeltaTimeValue; }

	private:
		static LARGE_INTEGER CpuFrequency; // long 2�� ���� 8����Ʈ
		static LARGE_INTEGER PrevFrequency; 
		static LARGE_INTEGER CurrentFrequency; 
		static float DeltaTimeValue; // �������� �ð����� 

	};
}


