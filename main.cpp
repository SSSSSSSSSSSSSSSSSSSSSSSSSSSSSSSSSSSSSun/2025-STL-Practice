//------------------------------------------------------------------
// 2025 STL ȭ56��78	5�� 8�� �����							(10�� 1��)
// 6�� 19�� ����� 15�� 2�� - �⸻ ����
//------------------------------------------------------------------
// VS ���� - 17.13 �̻�
// Release / x64, C++���ǥ�� - /std::c++latest, SDL �˻� - �ƴϿ�
//------------------------------------------------------------------
// STl Container - Containers are objects that store other objects.
// 1. Sequence Containers
//		array<T, N>
//		vector<T> - push_back() O(1)
//		deque<T> - push_front()/push_back() O(1)
//		list<T> - node ���, ������ ��ġ���� ���԰� ���� O(1)
//				- sort(), unique(), merge(), splice()
//		forward_list<T> -
//			It is intended that forward_list have zero space or time overhead
//			relative to a hand-written C-style singly linked list.
//			Features that would conflict with that goal have been omitted.
//------------------------------------------------------------------
#include <iostream>
#include <array>
#include <vector>
#include <deque>
#include <span>
#include "save.h"
#include "STRING.h"
// using namespace std;			// �츮�� �̷��� �ϸ� �ȵȴ�
// constexpr��?
// move semantic

extern bool watching;					// �����Ϸ��� true�� ����

void f(std::span<int> s)
{
	for (auto i = s.rbegin(); i != s.rend(); ++i) {
		std::cout << *i << " ";
	}
	std::cout << '\n';
}

int main()
{
	int a[]{ 1,2,3,4,5,6,7 };
	// �Ųٷ� ����϶�
	f(a);

	std::vector<int> v{ std::begin(a), std::end(a) };// { &a[0], &[7] };
	f(v);

	save("main.cpp");
}