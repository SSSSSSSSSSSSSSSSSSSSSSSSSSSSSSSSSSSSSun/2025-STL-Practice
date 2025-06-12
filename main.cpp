//------------------------------------------------------------------
// 2025 STL 화56목78	6월 10일 화요일							(14주 1일)
// 6월 19일 목요일 15주 2일 - 기말 시험
//------------------------------------------------------------------
// VS 버전 - 17.13 이상
// Release / x64, C++언어표준 - /std::c++latest, SDL 검사 - 아니오
//------------------------------------------------------------------
// 정렬관련 Algorithm을 알ㄹ아본다 - 복잡도 순으로
// 1. partition			- O(N)
// 2. nth_element
// 3. partial_sort
// 4. sort
// 5. stable_sort
//------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <list>
#include <concepts>
#include "save.h"
#include "STRING.h"
// using namespace std;					// 우리는 이렇게 하면 안된다
// constexpr란?
// move semantic

extern bool watching;					// 관찰하려면 true로 설정

template<class Iter>
std::iterator_traits<Iter>::difference_type my_distance(Iter begin, const Iter& end)
{
	// 만일 Iter가 random_access_iterator_tag 라면
	// C++20의 concept을 이용하면 판별이 쉽다.
	// tag-dispatch (C++20 이전)

	// C++17 이후에는 if-constexpr
	if constexpr (std::random_access_iterator<Iter>) {
		return end - begin;
	}
	else {
		typename std::iterator_traits<Iter>::difference_type d{};
		while (begin != end) {
			++begin;
			++d;
		}
		return d;
	}
}

int main()
{

	// 반복자간의 거리를 재는 std::distance 함수
	std::vector<int> v{ 1,2,3,4,5 };

	std::list<int> c{ 1,2,3,4,5 };

	std::cout << "vector의 distance - " << my_distance(v.end(), v.begin()) << std::endl;
	std::cout << "list의 distance - " << my_distance(c.end(), c.begin()) << std::endl;

	save("main.cpp");
}