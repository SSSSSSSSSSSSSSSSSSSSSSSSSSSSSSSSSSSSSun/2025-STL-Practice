//------------------------------------------------------------------
// 2025 STL ȭ56��78	4�� 17�� ȭ����				(7�� 2��)
// �߰����	(30) - 4�� 24�� ����� - ���� ��� : E�� 320ȣ
// 5�� 6�� (ȭ����) -> 6�� 19��(����) 
// �� �ڵ��� �ð��� ��� ���ؼ� ���� �� ������ �� ������ �ٷ�� ����?
//------------------------------------------------------------------
// VS ���� - 17.13 �̻�
// Release / x64, C++���ǥ�� - /std::c++latest, SDL �˻� - �ƴϿ�
//------------------------------------------------------------------
// STl Container - Containers are objects that store other objects.
// 1. Sequence Containers
//		array<T, N>
//		vector<T> - dynamic(run-time) array
//------------------------------------------------------------------
#include <iostream>
#include <vector>

#include "save.h"
#include "STRING.h"
// using namespace std;			// �츮�� �̷��� �ϸ� �ȵȴ�
// constexpr��?
// move semantic

extern bool watching;					// �����Ϸ��� true�� ����

// [����] vector�� ��� �޸𸮸� �����ϳ�
// ���� �޸𸮸� ��� ������ ȭ�鿡 ���

int main()
{
	watching = true;

	std::vector<STRING> v;

	v.emplace_back();
	std::cout << "v.back()�� �� STRING�� ID - " << v.back().getID() << '\n';
	

	save("main.cpp");
}