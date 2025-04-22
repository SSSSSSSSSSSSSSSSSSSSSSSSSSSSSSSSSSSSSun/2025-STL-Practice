//------------------------------------------------------------------
// 2025 STL 화56목78	4월 22일 화요일				(8주 1일)
// 중간고사	(30) - 4월 24일 목요일 - 시험 장소 : E동 320호
// 5월 6일 (화요일) -> 6월 19일(예정)
//------------------------------------------------------------------
// VS 버전 - 17.13 이상
// Release / x64, C++언어표준 - /std::c++latest, SDL 검사 - 아니오
//------------------------------------------------------------------
// STl Container - Containers are objects that store other objects.
// 1. Sequence Containers
//		array<T, N>
//		vector<T> - dynamic(run-time) array
//		deque<T> - vector보다 더 많은 원소를 담을 수 있다
//------------------------------------------------------------------
#include <iostream>
#include <deque>
#include "save.h"
#include "STRING.h"
// using namespace std;			// 우리는 이렇게 하면 안된다
// constexpr란?
// move semantic

extern bool watching;					// 관찰하려면 true로 설정

// a & 1

int main()
{
	watching = true;
	std::deque<STRING> d{ "1","22","333","4444" };

	for (const STRING& s : d) {
		std::cout << (void*)&s << '\n';
	}

	watching = false;
	save("main.cpp");
}