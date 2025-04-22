//------------------------------------------------------------------
// 2025 STL ȭ56��78	4�� 22�� ȭ����				(8�� 1��)
// �߰����	(30) - 4�� 24�� ����� - ���� ��� : E�� 320ȣ
// 5�� 6�� (ȭ����) -> 6�� 19��(����)
//------------------------------------------------------------------
// VS ���� - 17.13 �̻�
// Release / x64, C++���ǥ�� - /std::c++latest, SDL �˻� - �ƴϿ�
//------------------------------------------------------------------
// STl Container - Containers are objects that store other objects.
// 1. Sequence Containers
//		array<T, N>
//		vector<T> - dynamic(run-time) array
//		deque<T> - vector���� �� ���� ���Ҹ� ���� �� �ִ�
//------------------------------------------------------------------
#include <iostream>
#include <deque>
#include "save.h"
#include "STRING.h"
// using namespace std;			// �츮�� �̷��� �ϸ� �ȵȴ�
// constexpr��?
// move semantic

extern bool watching;					// �����Ϸ��� true�� ����

// a & 1

int main()
{
	watching = true;
	std::deque<STRING> d{ "1","22","333","4444" };

	for (const STRING& s : d) {
		std::cout << (void*)&s << '\n';
	}

	watching = false;
	save("main.cpp");
}