//------------------------------------------------------------------
// 2025 STL 화56목78	6월 17일 화요일							(15주 1일)
// 6월 19일 목요일 15주 2일 - 기말 시험
//------------------------------------------------------------------
// VS 버전 - 17.13 이상
// Release / x64, C++언어표준 - /std::c++latest, SDL 검사 - 아니오
//------------------------------------------------------------------
// iterator 라이브러리에서 제공하는 distance 함수 구현
// - 반복자 타입에 따라 다른 연산을 할 수 있다
// - 적절한 함수를 호출 - function dispatch
// - 함수를 호출하는 데 꼬리표를 달아 구분 - tag dispatch
// - C++17 이후에는
//   컴파일러가 조건에 맞지 않는 코드를 제거하는 if constexpr을 사용
// - C++20 부터는
//   concept을 사용하여 조건을 쉽게 판단할 수 있다.
//------------------------------------------------------------------
// concepts - 템플릿 함수의 인자는 자료형(아닌경우도 있다 - non-type template
// parameter)인데 이 자료형의 문법적 그리고 의미에서도 작성자가 의도한 것인지를
// compile-time에 판단하기 위한 C++ 언어의 기능
// 
// ranges와 concepts을 사용하여 STL의 라이브러리를 재작성한 것이
// constrained algorithm이다.
// 이 알고리즘들은 ranges::algorithm에 있다.
//------------------------------------------------------------------
#include <iostream>
#include <ranges>
#include <concepts>
#include <list>
#include "save.h"
#include "STRING.h"
// using namespace std;					// 우리는 이렇게 하면 안된다
// constexpr란?
// move semantic

extern bool watching;					// 관찰하려면 true로 설정

template <class T>
concept 덧셈가능 = std::is_integral_v<T> or std::is_floating_point_v<T>;

template<덧셈가능 T>
T add(T a, T b)
{
	return a + b;
}

int main(){

	// [문제] 한번에 해결할 add를 착성하라
	std::cout << add<int>(1, 2) << std::endl;
	std::cout << add<float>(1, 2) << std::endl;
	std::cout << add<STRING>(STRING("2025년"), STRING("6월 17일")) << std::endl;

	save("main.cpp");
}