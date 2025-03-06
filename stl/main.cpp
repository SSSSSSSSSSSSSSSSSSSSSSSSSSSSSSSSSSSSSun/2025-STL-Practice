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
#include <algorithm>
#include <chrono>

// [문제] save 함수를 제대로 코딩하라.
void save( std::string_view );

//----------
int main()
//----------
{

	std::cout << "2025 STL" << std::endl;
	
	save("main.cpp");
}

//----------
void save( std::string_view fileName)
//----------
{
	// fileName을 읽기모드로 연다
	std::ifstream in { fileName.data( ) };		// RAII
	if ( not in) {
		std::cout << fileName << "을 열 수 없습니다" << std::endl;
		exit(20250306);
	}

	// 쓰기모드로 저장할 파일을 연다
	std::string nameForSave{ "2025 1 STL 화56목78 강의저장.txt" };
	std::ofstream out{ nameForSave , std::ios::app };

	// 저장했다고 화면 출력

	auto size = std::filesystem::file_size(fileName);
	std::cout << nameForSave << "에 " << fileName << "을 덧붙였습니다. - "
		<< size << "Bytes" << std::endl;

	// 저장한 시간을 파일에 기록하자
	auto now = std::chrono::system_clock::now();				// time_point를 얻는다. epoch
	auto utc = std::chrono::system_clock::to_time_t(now);		// UTC 시간으로 변경
	auto lt = std::localtime( &utc );							// 지역달력 시간으로
	auto old = out.imbue(std::locale( "ko_KR" ));

	out << '\n' << '\n';
	out << "=================================================" << '\n';
	out << "저장한 시간: " << std::put_time(lt, "%c %A") << '\n';
	out << "=================================================" << '\n';
	out << '\n';

	out.imbue( old );			// 원 locale을 복구

	// 읽을 파일에 있는 모든 내용을 읽어 쓸 파일에 덧붙여 쓴다
	std::vector<char> v(size);
	std::copy(std::istreambuf_iterator{ in }, {}, std::ostreambuf_iterator{ out });
}