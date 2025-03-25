//------------------------------------------------------------------
// 2025 STL 화56목78	3월 25일 화요일					(4주 1일)
//------------------------------------------------------------------
// 동적할당과 smart pointer - RAII
//------------------------------------------------------------------
// VS 버전 - 17.13 이상
// Release / x64, C++언어표준 - /std::c++latest, SDL 검사 - 아니오
#include <iostream>
#include <fstream>
#include <algorithm>
#include "save.h"
// using namespace std;			// 우리는 이렇게 하면 안된다
// constexpr란?

//------------------------------------------------------------------
// 1. STACK
// 2. DATA
// 3. free-store
// 1,2번과 3번의 차이	- 메모리 크기를 언제 결정할 수 있는가
// 1번과 2번의 차이		- 메모리 크기가 얼마나 큰가
// 
// 다음 시간 이거 조금 더 설명하고 smart pointer로 직행 - 왜 RAII가 중요한가
//------------------------------------------------------------------
// [문제] "main.cpp"의 내용 중에 소문자를 모두 대문자로 바꿔 "main upper.cpp"에 저장하시오
//------------------------------------------------------------------



int main()
{
	std::ifstream in{ "main.cpp" };
	if (not in)
		return -1557;

	std::ofstream out{ "main upper.cpp" };
	
	std::transform(std::istreambuf_iterator<char>(in), {},
		std::ostreambuf_iterator<char>(out),
		[](char c) { return toupper(c); });
	
	save("main.cpp");
}