//------------------------------------------------------------------
// 2025 STL 화56목78	4월 15일 화요일				(7주 1일)
// 중간고사	(30) - 4월 24일 목요일
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
#include <numeric>
#include "save.h"
#include "STRING.h"
// using namespace std;			// 우리는 이렇게 하면 안된다
// constexpr란?
// move semantic

extern bool watching;					// 관찰하려면 true로 설정

// [문제] 키보드에서 입력한 정수값의 합계와 평균을 출력하라.

int main()
{
	std::cout << "정수를 마음껏 입력하라" << '\n';

	std::vector<int> v{ std::istream_iterator<int>{std::cin}, {} };

	long long sum{ std::accumulate(v.begin(), v.end(), 0LL) };
	std::cout << "합계입니다. - " << sum << '\n';
	std::cout << "평균입니다. - " << double(sum) / v.size() << '\n';
	save("main.cpp");
}