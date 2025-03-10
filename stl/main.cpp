//------------------------------------------------------------------
// 2025 STL 화56목78	3월 6일 목요일					(1주 2일)
//------------------------------------------------------------------
// 컴파일 환경 확인 / 한학기 강의를 저장할 save 만들기
// 과제 - save를 save.cpp로 분리하라
//------------------------------------------------------------------
// VS 버전 - 17.13 이상
// Release / x64, C++언어표준 - /std::c++latest, SDL 검사 - 아니오
#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>
#include <vector>
//#include <algorithm>
#include <chrono>
void save( std::string_view );

//----------
int main()
//----------
{

	std::cout << "2025 STL" << std::endl;
	
	save("main.cpp");
}