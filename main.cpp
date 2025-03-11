//------------------------------------------------------------------
// 2025 STL 화56목78	3월 6일 목요일					(1주 2일)
//------------------------------------------------------------------
// 많은 수의 자료를 처리하기
//------------------------------------------------------------------
// VS 버전 - 17.13 이상
// Release / x64, C++언어표준 - /std::c++latest, SDL 검사 - 아니오
#include <iostream>
#include <random>
#include <print>
#include "save.h"
// using namespace std;			// 우리는 이렇게 하면 안된다
// 
// [문제] 랜덤 int 1000개를 메모리에 저장하라
// 가장 큰 값을 찾아 화면에 출력하라

std::default_random_engine dre;
std::uniform_int_distribution uid{ 0,9999999 };

int main()
{
	for (int i = 0; i < 1000; ++i) {
		std::print("{:8}", uid(dre));
	}

	save("main.cpp");
}