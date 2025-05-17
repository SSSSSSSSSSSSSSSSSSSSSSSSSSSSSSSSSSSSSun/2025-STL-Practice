//------------------------------------------------------------------
// 2025 STL ȭ56��78	5�� 13�� ȭ����							(10�� 2��)
// 6�� 19�� ����� 15�� 2�� - �⸻ ����
//------------------------------------------------------------------
// VS ���� - 17.13 �̻�
// Release / x64, C++���ǥ�� - /std::c++latest, SDL �˻� - �ƴϿ�
//------------------------------------------------------------------
// Iterator - Iterators are a generalization of pointers
//			  that allow a C++ program to work with different data structures in a uniform manner.
// 
// �ݺ��ڴ� Ŭ������ �ڵ��ؾ� �մϴ�.
//------------------------------------------------------------------
#include <iostream>
#include <algorithm>
#include "save.h"
#include "STRING.h"
// using namespace std;					// �츮�� �̷��� �ϸ� �ȵȴ�
// constexpr��?
// move semantic

extern bool watching;					// �����Ϸ��� true�� ����

int main()
{
	STRING s{ "2025 5 15" };

	// �������� ����ǰ� ����
	std::sort(s.begin(), s.end());

	std::cout << s << '\n';				// "   01225555"
	
	save("main.cpp");
}