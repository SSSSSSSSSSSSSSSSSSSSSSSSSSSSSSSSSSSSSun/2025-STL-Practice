//------------------------------------------------------------------
// 2025 STL 화56목78	4월 10일 화요일				(6주 2일)
// 중간고사	(30) - 4월 24일 목요일
// 5월 6일 (화요일) -> 6월 19일(예정) 
// 두 코드의 시간을 재고 비교해서 뭐가 더 빠르고 왜 빠른지 다루는 문제?
//------------------------------------------------------------------
// VS 버전 - 17.13 이상
// Release / x64, C++언어표준 - /std::c++latest, SDL 검사 - 아니오


//------------------------------------------------------------------
// STRING - std::string과 유사한 클래스, STL 표준 컨테이너가 되도록..
//			내부 동작을 관찰할 수 있게 하자
//------------------------------------------------------------------
#include <iostream>
#include <array>
#include <algorithm>
#include "save.h"
#include "STRING.h"
// using namespace std;			// 우리는 이렇게 하면 안된다
// constexpr란?
// move semantic

extern bool watching;					// 관찰하려면 true로 설정

int main()
{
	

	std::array<STRING, 5> a{ "1","333","55555", "22", "4444" };
	// 정렬
	std::sort(a.begin(), a.end(), [](const STRING& lhs, const STRING& rhs){
		return lhs.size() < rhs.size();
		})
		;
	// 출력
	for (const STRING& str : a) {
		std::cout << str << '\n';
	}


	save("main.cpp");
}