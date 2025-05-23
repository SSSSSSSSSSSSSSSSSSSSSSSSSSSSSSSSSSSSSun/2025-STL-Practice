//------------------------------------------------------------------
// 2025 STL 화56목78	3월 25일 화요일					(4주 1일)
//------------------------------------------------------------------
// 동적할당과 SMART POINTER - RAII
//------------------------------------------------------------------
// VS 버전 - 17.13 이상
// RELEASE / X64, C++언어표준 - /STD::C++LATEST, SDL 검사 - 아니오
#INCLUDE <IOSTREAM>
#INCLUDE <FSTREAM>
#INCLUDE <ALGORITHM>
#INCLUDE "SAVE.H"
// USING NAMESPACE STD;			// 우리는 이렇게 하면 안된다
// CONSTEXPR란?

//------------------------------------------------------------------
// 1. STACK
// 2. DATA
// 3. FREE-STORE
// 1,2번과 3번의 차이	- 메모리 크기를 언제 결정할 수 있는가
// 1번과 2번의 차이		- 메모리 크기가 얼마나 큰가
// 
// 다음 시간 이거 조금 더 설명하고 SMART POINTER로 직행 - 왜 RAII가 중요한가
//------------------------------------------------------------------
// [문제] "MAIN.CPP"의 내용 중에 소문자를 모두 대문자로 바꿔 "MAIN UPPER.CPP"에 저장하시오
//------------------------------------------------------------------



INT MAIN()
{
	STD::IFSTREAM IN{ "MAIN.CPP" };
	IF (NOT IN)
		RETURN -1557;

	STD::OFSTREAM OUT{ "MAIN UPPER.CPP" };
	
	STD::TRANSFORM(STD::ISTREAMBUF_ITERATOR<CHAR>(IN), {},
		STD::OSTREAMBUF_ITERATOR<CHAR>(OUT),
		[](CHAR C) { RETURN TOUPPER(C); });
	
	SAVE("MAIN.CPP");
}