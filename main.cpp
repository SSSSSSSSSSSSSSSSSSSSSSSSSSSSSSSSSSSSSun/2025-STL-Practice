//------------------------------------------------------------------
// 2025 STL ȭ56��78	4�� 3�� ȭ����				(5�� 2��)
// �߰����	(30) - 4�� 24�� �����
// ����		(30) - 4�� 10�� ����
// ���� 1 - ������ �о�(text/binary) �޸𸮿� ������ �� �ٷ�� ����?
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
	
extern bool watching;					// �����Ϸ��� true�� ����

int main()
{

	std::array<STRING, 5> a{ "1", "333", "22" , "55555", "4444" };

	// ���� ���� �������� �����ϰ� ����϶�
	watching = true;
	std::sort(a.begin(), a.end(),
		[](const STRING& rhs, const STRING& lhs) {
			return rhs.size() < lhs.size();
		});
	watching = false;
	
	
	for (const STRING& str : a) {
		std::cout << str << '\n';
	}
	

	save("main.cpp");
}