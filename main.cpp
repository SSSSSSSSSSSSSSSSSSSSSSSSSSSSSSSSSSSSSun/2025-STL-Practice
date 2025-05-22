//------------------------------------------------------------------
// 2025 STL 화56목78	5월 22일 목요일							(12주 1일)
// 6월 19일 목요일 15주 2일 - 기말 시험
//------------------------------------------------------------------
// VS 버전 - 17.13 이상
// Release / x64, C++언어표준 - /std::c++latest, SDL 검사 - 아니오
//------------------------------------------------------------------
// Associative Container	- key와 연관된 value를 항상 정렬상태로 유지한다.
//							  정렬은 key 값을 기준으로 한다
//  set / multiset			- key == value
//  map / multimap			- pair<key, value>
//------------------------------------------------------------------
#include <iostream>
#include <set>
#include <ranges>
#include "save.h"
#include "STRING.h"
// using namespace std;					// 우리는 이렇게 하면 안된다
// constexpr란?
// move semantic

extern bool watching;					// 관찰하려면 true로 설정

// template을 specialization 한다
template <>
struct std::less<STRING> {
public:
	bool operator()(const STRING& a, const STRING& b) const {
		return a.size() < b.size();
	}
};


int main()
{
	
	// [문제] s를 기본정렬 기준인 less를 사용하여 바이트 수 기준으로 정렬되게 하자
	std::set<STRING> s{ "333", "2222", "11111", "44", "5"};

	for (const STRING& str : s) {
		std::cout << str << '\n';
	}
	std::cout << '\n';


	save("main.cpp");
}