//------------------------------------------------------------------
// 2025 STL ȭ56��78	6�� 10�� ȭ����							(14�� 1��)
// 6�� 19�� ����� 15�� 2�� - �⸻ ����
//------------------------------------------------------------------
// VS ���� - 17.13 �̻�
// Release / x64, C++���ǥ�� - /std::c++latest, SDL �˻� - �ƴϿ�
//------------------------------------------------------------------
// Algorithm - cppreference
//------------------------------------------------------------------
#include <iostream>
#include <string>
#include <algorithm>
#include "save.h"
#include "STRING.h"
// using namespace std;					// �츮�� �̷��� �ϸ� �ȵȴ�
// constexpr��?
// move semantic

extern bool watching;					// �����Ϸ��� true�� ����

int main()
{
	std::string s{ "2025. 6. 10." };

	while (1) {
		std::cout << s << '\n';
		// 100ms ����
		std::rotate(s.begin(), s.end(), s.begin() + 1);
	}

	save("main.cpp");
}