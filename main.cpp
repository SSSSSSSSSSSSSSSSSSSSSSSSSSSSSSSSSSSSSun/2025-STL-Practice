//------------------------------------------------------------------
// 2025 STL 화56목78	5월 27일 목요일							(13주 1일)
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
#include <fstream>
#include <algorithm>
#include <set>
#include <vector>
#include "save.h"
#include "STRING.h"
// using namespace std;					// 우리는 이렇게 하면 안된다
// constexpr란?
// move semantic

extern bool watching;					// 관찰하려면 true로 설정

// 강의자료 "이상한 나라의 앨리스.txt"를 다운받는다.
// [1] 여기에 있는 모든 단어를 multiset<STRING>로 저장하라.
// [2] 모두 몇 단어 인지 화면에 출력하라. - 26626
// 

int main()
{
	std::ifstream in { "이상한 나라의 앨리스.txt" };

	if (not in) {
		return -1557;
	}

	std::multiset<STRING> ms{ std::istream_iterator<STRING>{in}, {} };
	std::cout << "set으로 복사한 단어의 수 - " << ms.size() << '\n';

	for (const STRING& s : ms) {
		std::cout << s << " ";
	}
	std::cout << '\n';

	// 동일 단어가 몇 개 있는지 알려주자

	while (true) {
		STRING target;
		std::cin >> target;

		std::cout << ms.count(target) << '\n';
	}


	save("main.cpp");
}