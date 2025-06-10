//------------------------------------------------------------------
// 2025 STL 화56목78	6월 10일 화요일							(14주 1일)
// 6월 19일 목요일 15주 2일 - 기말 시험
//------------------------------------------------------------------
// VS 버전 - 17.13 이상
// Release / x64, C++언어표준 - /std::c++latest, SDL 검사 - 아니오
//------------------------------------------------------------------
// Algorithm - cppreference
//------------------------------------------------------------------
#include <iostream>
#include <string>
#include <algorithm>
#include "save.h"
#include "STRING.h"
// using namespace std;					// 우리는 이렇게 하면 안된다
// constexpr란?
// move semantic

extern bool watching;					// 관찰하려면 true로 설정

int main()
{
	std::string s{ "2025. 6. 10." };

	while (1) {
		std::cout << s << '\n';
		// 100ms 쉬고
		std::rotate(s.begin(), s.end(), s.begin() + 1);
	}

	save("main.cpp");
}