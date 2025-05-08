//------------------------------------------------------------------
// 2025 STL 화56목78	5월 8일 목요일							(10주 1일)
// 6월 19일 목요일 15주 2일 - 기말 시험
//------------------------------------------------------------------
// VS 버전 - 17.13 이상
// Release / x64, C++언어표준 - /std::c++latest, SDL 검사 - 아니오
//------------------------------------------------------------------
// STl Container - Containers are objects that store other objects.
// 1. Sequence Containers
//		array<T, N>
//		vector<T> - push_back() O(1)
//		deque<T> - push_front()/push_back() O(1)
//		list<T> - node 기반, 임의의 위치에서 삽입과 삭제 O(1)
//				- sort(), unique(), merge(), splice()
//		forward_list<T> -
//			It is intended that forward_list have zero space or time overhead
//			relative to a hand-written C-style singly linked list.
//			Features that would conflict with that goal have been omitted.
//------------------------------------------------------------------
#include <iostream>
#include <array>
#include <vector>
#include <deque>
#include <span>
#include "save.h"
#include "STRING.h"
// using namespace std;			// 우리는 이렇게 하면 안된다
// constexpr란?
// move semantic

extern bool watching;					// 관찰하려면 true로 설정

void f(std::span<int> s)
{
	for (auto i = s.rbegin(); i != s.rend(); ++i) {
		std::cout << *i << " ";
	}
	std::cout << '\n';
}

int main()
{
	int a[]{ 1,2,3,4,5,6,7 };
	// 거꾸로 출력하라
	f(a);

	std::vector<int> v{ std::begin(a), std::end(a) };// { &a[0], &[7] };
	f(v);

	save("main.cpp");
}