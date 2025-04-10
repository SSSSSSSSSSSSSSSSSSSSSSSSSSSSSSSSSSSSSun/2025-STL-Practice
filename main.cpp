//------------------------------------------------------------------
// 2025 STL ȭ56��78	4�� 10�� ȭ����				(6�� 2��)
// �߰����	(30) - 4�� 24�� �����
// 5�� 6�� (ȭ����) -> 6�� 19��(����) 
// �� �ڵ��� �ð��� ��� ���ؼ� ���� �� ������ �� ������ �ٷ�� ����?
//------------------------------------------------------------------
// VS ���� - 17.13 �̻�
// Release / x64, C++���ǥ�� - /std::c++latest, SDL �˻� - �ƴϿ�


//------------------------------------------------------------------
// STRING - std::string�� ������ Ŭ����, STL ǥ�� �����̳ʰ� �ǵ���..
//			���� ������ ������ �� �ְ� ����
//------------------------------------------------------------------
#include <iostream>
#include <array>
#include <algorithm>
#include "save.h"
#include "STRING.h"
// using namespace std;			// �츮�� �̷��� �ϸ� �ȵȴ�
// constexpr��?
// move semantic

extern bool watching;					// �����Ϸ��� true�� ����

int main()
{
	

	std::array<STRING, 5> a{ "1","333","55555", "22", "4444" };
	// ����
	std::sort(a.begin(), a.end(), [](const STRING& lhs, const STRING& rhs){
		return lhs.size() < rhs.size();
		})
		;
	// ���
	for (const STRING& str : a) {
		std::cout << str << '\n';
	}


	save("main.cpp");
}