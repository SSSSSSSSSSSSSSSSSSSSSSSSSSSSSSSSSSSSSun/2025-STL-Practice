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