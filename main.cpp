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
#include <string>
#include <iterator>
#include <array>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>
#include "save.h"
#include "STRING.h"
// using namespace std;			// 우리는 이렇게 하면 안된다
// constexpr란?
// move semantic

extern bool watching;					// 관찰하려면 true로 설정

template<class Iterator>
void f(Iterator i)
{
	// 종류
	std::cout << "반복자의 타입 - " << typeid(Iterator::iterator_category).name() << '\n';
}

int main()
{
	// [문제] 반복자는 종류(6 category)가 있다.
	// 함수 f는 반복자를 인자로 받아 어떤 종류의 반복자인지 화면에 출력하는 함수이다.
	// 다음 코드가 문제없이 실행되게 하자.

	//f(std::array<int, 0>::iterator{});
	std::array<int, 2> a;
	f(a.begin());

	std::vector<char> v;
	f(v.end());

	f(std::deque<STRING>::iterator{});
	f(std::list<int>{}.rbegin());
	f(std::forward_list<int>::const_iterator{});

	f(std::ostream_iterator<char>{std::cout});

	save("main.cpp");
}