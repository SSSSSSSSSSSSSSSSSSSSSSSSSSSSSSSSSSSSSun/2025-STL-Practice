//------------------------------------------------------------------
// 2025 STL 화56목78	5월 13일 화요일							(10주 2일)
// 6월 19일 목요일 15주 2일 - 기말 시험
//------------------------------------------------------------------
// VS 버전 - 17.13 이상
// Release / x64, C++언어표준 - /std::c++latest, SDL 검사 - 아니오
//------------------------------------------------------------------
// Iterator - Iterators are a generalization of pointers
//			  that allow a C++ program to work with different data structures in a uniform manner.
// 
// 반복자는 클래스로 코딩해야 합니다.
//------------------------------------------------------------------
#include <iostream>
#include <algorithm>
#include "save.h"
#include "STRING.h"
// using namespace std;					// 우리는 이렇게 하면 안된다
// constexpr란?
// move semantic

extern bool watching;					// 관찰하려면 true로 설정

int main()
{
	STRING s{ "2025 5 15" };

	// 문제없이 실행되게 하자
	std::sort(s.begin(), s.end());

	std::cout << s << '\n';				// "   01225555"
	
	save("main.cpp");
}