//------------------------------------------------------------------
// 2025 STL ȭ56��78	3�� 25�� ȭ����					(4�� 1��)
//------------------------------------------------------------------
// �����Ҵ�� smart pointer - RAII
//------------------------------------------------------------------
// VS ���� - 17.13 �̻�
// Release / x64, C++���ǥ�� - /std::c++latest, SDL �˻� - �ƴϿ�
#include <iostream>
#include <fstream>
#include <algorithm>
#include "save.h"
// using namespace std;			// �츮�� �̷��� �ϸ� �ȵȴ�
// constexpr��?

//------------------------------------------------------------------
// 1. STACK
// 2. DATA
// 3. free-store
// 1,2���� 3���� ����	- �޸� ũ�⸦ ���� ������ �� �ִ°�
// 1���� 2���� ����		- �޸� ũ�Ⱑ �󸶳� ū��
// 
// ���� �ð� �̰� ���� �� �����ϰ� smart pointer�� ���� - �� RAII�� �߿��Ѱ�
//------------------------------------------------------------------
// [����] "main.cpp"�� ���� �߿� �ҹ��ڸ� ��� �빮�ڷ� �ٲ� "main upper.cpp"�� �����Ͻÿ�
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