//------------------------------------------------------------------
// 2025 STL 화56목78	4월 17일 화요일				(7주 2일)
// 중간고사	(30) - 4월 24일 목요일 - 시험 장소 : E동 320호
// 5월 6일 (화요일) -> 6월 19일(예정) 
// 두 코드의 시간을 재고 비교해서 뭐가 더 빠르고 왜 빠른지 다루는 문제?
//------------------------------------------------------------------
// VS 버전 - 17.13 이상
// Release / x64, C++언어표준 - /std::c++latest, SDL 검사 - 아니오
//------------------------------------------------------------------
// STl Container - Containers are objects that store other objects.
// 1. Sequence Containers
//		array<T, N>
//		vector<T> - dynamic(run-time) array
//------------------------------------------------------------------
#include <iostream>
#include <vector>

#include "save.h"
#include "STRING.h"
// using namespace std;			// 우리는 이렇게 하면 안된다
// constexpr란?
// move semantic

extern bool watching;					// 관찰하려면 true로 설정

// [문제] vector는 어떻게 메모리를 관리하나
// 새로 메모리를 잡는 순간만 화면에 출력

int main()
{
	watching = true;

	std::vector<STRING> v;

	v.emplace_back();
	std::cout << "v.back()에 들어간 STRING의 ID - " << v.back().getID() << '\n';
	

	save("main.cpp");
}