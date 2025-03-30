//------------------------------------------------------------------
// 2025 STL 화56목78	3월 27일 목요일					(4주 2일)
//------------------------------------------------------------------
// Callable type - 호출가능한 타입
// 1. 함수
//------------------------------------------------------------------
// VS 버전 - 17.13 이상
// Release / x64, C++언어표준 - /std::c++latest, SDL 검사 - 아니오
#include <iostream>
#include <random>
#include <array>
#include <memory>
#include <print>
#include <ranges>
#include <algorithm>
#include <chrono>
#include "save.h"
// using namespace std;			// 우리는 이렇게 하면 안된다
// constexpr란?

// [문제] 랜덤 int 1000만개를 메모리에 저장하자.
// 랜덤 int 값의 범위는 [0, 10'000'000) ===> 0부터 9'999'999까지 값을 갖도록
// C++ 언어의 sort를 사용하여 오름차순으로 정렬하라
// 정렬한 결과를 앞에서 부터 1000개만 화면에 출력하라

std::default_random_engine dre;

bool ascendingOrder(const int a, const int b)
{
	return a < b;
}

int main()
{
	std::uniform_int_distribution uid{ 0,9'999'999 };
	std::unique_ptr<std::array<int, 10'000'000>> upArray = std::make_unique<std::array<int, 10'000'000>>();

	{
		for (int& num : *upArray) {
			num = uid(dre);
		}
		// 정렬에 걸리는 시간 측정
		auto b = std::chrono::high_resolution_clock::now();						// 스톱워치 시작
		std::sort(upArray->begin(), upArray->end(), ascendingOrder);			// 디폴트 정렬 operator <
		auto e = std::chrono::high_resolution_clock::now();						// 스톱워치 끝

		/*for (int num : *upArray | std::ranges::views::take(3000)) {
			std::print("{:8}", num);
		}*/
		std::cout << "경과시간(ms) - " << std::chrono::duration_cast<std::chrono::milliseconds>(e - b) << '\n';
	}

	{	// 내림차순으로 정렬
		for (int& num : *upArray) {
			num = uid(dre);
		}
		// 정렬에 걸리는 시간 측정
		auto b = std::chrono::high_resolution_clock::now();						// 스톱워치 시작
		std::sort<std::array<int,10'000'000>::iterator>(upArray->begin(), upArray->end(),[](const int a, const int b) {
			return a > b;
			});
		auto e = std::chrono::high_resolution_clock::now();						// 스톱워치 끝

		/*for (int num : *upArray | std::ranges::views::take(3000)) {
			std::print("{:8}", num);
		}*/
		std::cout << "경과시간(ms) - " << std::chrono::duration_cast<std::chrono::milliseconds>(e - b) << '\n';
	}

	save("main.cpp");
}