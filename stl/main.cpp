//------------------------------------------------------------------
// 2025 STL ȭ56��78	3�� 6�� �����					(1�� 2��)
//------------------------------------------------------------------
// ������ ȯ�� Ȯ�� / ���б� ���Ǹ� ������ save �����
// ���� - save�� save.cpp�� �и��϶�
//------------------------------------------------------------------
// VS ���� - 17.13 �̻�
// Release / x64, C++���ǥ�� - /std::c++latest, SDL �˻� - �ƴϿ�
#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>
#include <vector>
#include <algorithm>
#include <chrono>

// [����] save �Լ��� ����� �ڵ��϶�.
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
	// fileName�� �б���� ����
	std::ifstream in { fileName.data( ) };		// RAII
	if ( not in) {
		std::cout << fileName << "�� �� �� �����ϴ�" << std::endl;
		exit(20250306);
	}

	// ������� ������ ������ ����
	std::string nameForSave{ "2025 1 STL ȭ56��78 ��������.txt" };
	std::ofstream out{ nameForSave , std::ios::app };

	// �����ߴٰ� ȭ�� ���

	auto size = std::filesystem::file_size(fileName);
	std::cout << nameForSave << "�� " << fileName << "�� ���ٿ����ϴ�. - "
		<< size << "Bytes" << std::endl;

	// ������ �ð��� ���Ͽ� �������
	auto now = std::chrono::system_clock::now();				// time_point�� ��´�. epoch
	auto utc = std::chrono::system_clock::to_time_t(now);		// UTC �ð����� ����
	auto lt = std::localtime( &utc );							// �����޷� �ð�����
	auto old = out.imbue(std::locale( "ko_KR" ));

	out << '\n' << '\n';
	out << "=================================================" << '\n';
	out << "������ �ð�: " << std::put_time(lt, "%c %A") << '\n';
	out << "=================================================" << '\n';
	out << '\n';

	out.imbue( old );			// �� locale�� ����

	// ���� ���Ͽ� �ִ� ��� ������ �о� �� ���Ͽ� ���ٿ� ����
	std::vector<char> v(size);
	std::copy(std::istreambuf_iterator{ in }, {}, std::ostreambuf_iterator{ out });
}