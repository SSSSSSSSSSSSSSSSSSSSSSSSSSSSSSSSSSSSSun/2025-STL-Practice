//------------------------------------------------------------------
// 2025 STL ȭ56��78	5�� 22�� �����							(12�� 1��)
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
#include <set>
#include <ranges>
#include "save.h"
#include "STRING.h"
// using namespace std;					// �츮�� �̷��� �ϸ� �ȵȴ�
// constexpr��?
// move semantic

extern bool watching;					// �����Ϸ��� true�� ����

// template�� specialization �Ѵ�
template <>
struct std::less<STRING> {
public:
	bool operator()(const STRING& a, const STRING& b) const {
		return a.size() < b.size();
	}
};


int main()
{
	
	// [����] s�� �⺻���� ������ less�� ����Ͽ� ����Ʈ �� �������� ���ĵǰ� ����
	std::set<STRING> s{ "333", "2222", "11111", "44", "5"};

	for (const STRING& str : s) {
		std::cout << str << '\n';
	}
	std::cout << '\n';


	save("main.cpp");
}