//------------------------------------------------------------------
// 2025 STL 화56목78	5월 29일 목요일							(13주 1일)
// 6월 19일 목요일 15주 2일 - 기말 시험
//------------------------------------------------------------------
// VS 버전 - 17.13 이상
// Release / x64, C++언어표준 - /std::c++latest, SDL 검사 - 아니오
//------------------------------------------------------------------
// Unordered Associative Containers - hash 구조
//------------------------------------------------------------------
#include <iostream>
#include <unordered_set>
#include <print>
#include "save.h"
#include "STRING.h"
// using namespace std;					// 우리는 이렇게 하면 안된다
// constexpr란?
// move semantic

extern bool watching;					// 관찰하려면 true로 설정

template <>
struct std::hash<STRING> {
	size_t operator()(const STRING& s) const {
		//std::string str(s.begin(), s.end());
		return std::hash<std::string>{}(std::string(s.begin(), s.end()));
	}
};

int main()
{

	std::unordered_set<STRING, std::hash<STRING>> us{"1", "22", "333", "4444", "55555"};

	for (const STRING& s : us) {
		std::cout << s << '\n';
	}

	// unordered_set의 메모리를 화면에 출력한다.

	while (true) {
		for (size_t bc = 0; bc < us.bucket_count(); ++bc) {
			std::print("[{:>3}]", bc);
			for (auto i = us.begin(bc); i != us.end(bc); ++i) {
				std::print(" -> {:}", std::string{ i->begin(), i->end() });
			}

			std::cout << '\n';
		}

		std::cout << "추가할 STRING - ";
		STRING s;
		std::cin >> s;

		us.insert(s);
	}
	save("main.cpp");
}