//------------------------------------------------------------------
// 2025 STL ȭ56��78	5�� 27�� �����							(13�� 1��)
// 6�� 19�� ����� 15�� 2�� - �⸻ ����
//------------------------------------------------------------------
// VS ���� - 17.13 �̻�
// Release / x64, C++���ǥ�� - /std::c++latest, SDL �˻� - �ƴϿ�
//------------------------------------------------------------------
// Associative Container	- key�� ������ value�� �׻� ���Ļ��·� �����Ѵ�.
//							  ������ key ���� �������� �Ѵ�
//  set / multiset			- key == value
//  map / multimap			- pair<key, value>
//------------------------------------------------------------------
#include <iostream>
#include <fstream>
#include <algorithm>
#include <set>
#include <vector>
#include "save.h"
#include "STRING.h"
// using namespace std;					// �츮�� �̷��� �ϸ� �ȵȴ�
// constexpr��?
// move semantic

extern bool watching;					// �����Ϸ��� true�� ����

// �����ڷ� "�̻��� ������ �ٸ���.txt"�� �ٿ�޴´�.
// [1] ���⿡ �ִ� ��� �ܾ multiset<STRING>�� �����϶�.
// [2] ��� �� �ܾ� ���� ȭ�鿡 ����϶�. - 26626
// 

int main()
{
	std::ifstream in { "�̻��� ������ �ٸ���.txt" };

	if (not in) {
		return -1557;
	}

	std::multiset<STRING> ms{ std::istream_iterator<STRING>{in}, {} };
	std::cout << "set���� ������ �ܾ��� �� - " << ms.size() << '\n';

	for (const STRING& s : ms) {
		std::cout << s << " ";
	}
	std::cout << '\n';

	// ���� �ܾ �� �� �ִ��� �˷�����

	while (true) {
		STRING target;
		std::cin >> target;

		std::cout << ms.count(target) << '\n';
	}


	save("main.cpp");
}