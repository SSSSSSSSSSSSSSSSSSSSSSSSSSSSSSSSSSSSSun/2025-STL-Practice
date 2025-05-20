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
#include <algorithm>
#include <vector>
#include "save.h"
#include "STRING.h"
// using namespace std;					// �츮�� �̷��� �ϸ� �ȵȴ�
// constexpr��?
// move semantic

extern bool watching;					// �����Ϸ��� true�� ����

template<class �ݺ���, class ��>
�ݺ��� my_find(�ݺ��� b, �ݺ��� e, �� v)
{
	while (b != e) {
		if (v == *b) {
			return b;
		}
		++b;
	}
	return b;
}

template<class �ݺ���, class Pred>
�ݺ��� myfind_if(�ݺ��� b, �ݺ��� e, Pred f)
{
	for (; b != e; ++b) {
		if (f(*b)) { return b; }
	}
	return e;
}

template<class �ݺ���, class �������ݺ���>
void my_copy(�ݺ��� b, �ݺ��� e, �������ݺ��� d)
{
	while (b != e) {
		*d = *b;
		++d;
		++b;
	}
}

int main()
{

	STRING s{ "�ݺ��ڸ� ����� �˰����� ���� ��" };
	std::vector<char> v{ '1' };

	my_copy(s.begin(), s.end(), back_inserter(v));
	
	for (char c : v) {
		std::cout << c;
	}

	std::cout << '\n';

	save("main.cpp");
}