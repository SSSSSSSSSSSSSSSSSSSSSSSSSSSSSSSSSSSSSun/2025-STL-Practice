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
#include <vector>
#include "save.h"
#include "STRING.h"
// using namespace std;					// 우리는 이렇게 하면 안된다
// constexpr란?
// move semantic

extern bool watching;					// 관찰하려면 true로 설정

template<class 반복자, class 값>
반복자 my_find(반복자 b, 반복자 e, 값 v)
{
	while (b != e) {
		if (v == *b) {
			return b;
		}
		++b;
	}
	return b;
}

template<class 반복자, class Pred>
반복자 myfind_if(반복자 b, 반복자 e, Pred f)
{
	for (; b != e; ++b) {
		if (f(*b)) { return b; }
	}
	return e;
}

template<class 반복자, class 목적지반복자>
void my_copy(반복자 b, 반복자 e, 목적지반복자 d)
{
	while (b != e) {
		*d = *b;
		++d;
		++b;
	}
}

int main()
{

	STRING s{ "반복자를 사용한 알고리즘을 연습 중" };
	std::vector<char> v{ '1' };

	my_copy(s.begin(), s.end(), back_inserter(v));
	
	for (char c : v) {
		std::cout << c;
	}

	std::cout << '\n';

	save("main.cpp");
}