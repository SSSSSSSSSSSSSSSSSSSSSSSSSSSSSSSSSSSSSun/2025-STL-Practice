//------------------------------------------------------------------
// 2025 STL ȭ56��78	4�� 15�� ȭ����				(7�� 1��)
// �߰����	(30) - 4�� 24�� �����
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
#include <numeric>
#include "save.h"
#include "STRING.h"
// using namespace std;			// �츮�� �̷��� �ϸ� �ȵȴ�
// constexpr��?
// move semantic

extern bool watching;					// �����Ϸ��� true�� ����

// [����] Ű���忡�� �Է��� �������� �հ�� ����� ����϶�.

int main()
{
	std::cout << "������ ������ �Է��϶�" << '\n';

	std::vector<int> v{ std::istream_iterator<int>{std::cin}, {} };

	long long sum{ std::accumulate(v.begin(), v.end(), 0LL) };
	std::cout << "�հ��Դϴ�. - " << sum << '\n';
	std::cout << "����Դϴ�. - " << double(sum) / v.size() << '\n';
	save("main.cpp");
}