//------------------------------------------------------------------
// 2025 STL ȭ56��78	6�� 10�� ȭ����							(14�� 1��)
// 6�� 19�� ����� 15�� 2�� - �⸻ ����
//------------------------------------------------------------------
// VS ���� - 17.13 �̻�
// Release / x64, C++���ǥ�� - /std::c++latest, SDL �˻� - �ƴϿ�
//------------------------------------------------------------------
// ���İ��� Algorithm�� �ˤ��ƺ��� - ���⵵ ������
// 1. partition			- O(N)
// 2. nth_element
// 3. partial_sort
// 4. sort
// 5. stable_sort
//------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <list>
#include <concepts>
#include "save.h"
#include "STRING.h"
// using namespace std;					// �츮�� �̷��� �ϸ� �ȵȴ�
// constexpr��?
// move semantic

extern bool watching;					// �����Ϸ��� true�� ����

template<class Iter>
std::iterator_traits<Iter>::difference_type my_distance(Iter begin, const Iter& end)
{
	// ���� Iter�� random_access_iterator_tag ���
	// C++20�� concept�� �̿��ϸ� �Ǻ��� ����.
	// tag-dispatch (C++20 ����)

	// C++17 ���Ŀ��� if-constexpr
	if constexpr (std::random_access_iterator<Iter>) {
		return end - begin;
	}
	else {
		typename std::iterator_traits<Iter>::difference_type d{};
		while (begin != end) {
			++begin;
			++d;
		}
		return d;
	}
}

int main()
{

	// �ݺ��ڰ��� �Ÿ��� ��� std::distance �Լ�
	std::vector<int> v{ 1,2,3,4,5 };

	std::list<int> c{ 1,2,3,4,5 };

	std::cout << "vector�� distance - " << my_distance(v.end(), v.begin()) << std::endl;
	std::cout << "list�� distance - " << my_distance(c.end(), c.begin()) << std::endl;

	save("main.cpp");
}