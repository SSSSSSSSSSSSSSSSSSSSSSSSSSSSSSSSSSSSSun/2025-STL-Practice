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
#include <string>
#include <iterator>
#include <array>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>
#include "save.h"
#include "STRING.h"
// using namespace std;			// �츮�� �̷��� �ϸ� �ȵȴ�
// constexpr��?
// move semantic

extern bool watching;					// �����Ϸ��� true�� ����

template<class Iterator>
void f(Iterator i)
{
	// ����
	std::cout << "�ݺ����� Ÿ�� - " << typeid(Iterator::iterator_category).name() << '\n';
}

int main()
{
	// [����] �ݺ��ڴ� ����(6 category)�� �ִ�.
	// �Լ� f�� �ݺ��ڸ� ���ڷ� �޾� � ������ �ݺ������� ȭ�鿡 ����ϴ� �Լ��̴�.
	// ���� �ڵ尡 �������� ����ǰ� ����.

	//f(std::array<int, 0>::iterator{});
	std::array<int, 2> a;
	f(a.begin());

	std::vector<char> v;
	f(v.end());

	f(std::deque<STRING>::iterator{});
	f(std::list<int>{}.rbegin());
	f(std::forward_list<int>::const_iterator{});

	f(std::ostream_iterator<char>{std::cout});

	save("main.cpp");
}