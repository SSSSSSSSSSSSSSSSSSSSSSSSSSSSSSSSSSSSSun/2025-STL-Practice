//------------------------------------------------------------------
// 2025 STL ȭ56��78	6�� 17�� ȭ����							(15�� 1��)
// 6�� 19�� ����� 15�� 2�� - �⸻ ����
//------------------------------------------------------------------
// VS ���� - 17.13 �̻�
// Release / x64, C++���ǥ�� - /std::c++latest, SDL �˻� - �ƴϿ�
//------------------------------------------------------------------
// iterator ���̺귯������ �����ϴ� distance �Լ� ����
// - �ݺ��� Ÿ�Կ� ���� �ٸ� ������ �� �� �ִ�
// - ������ �Լ��� ȣ�� - function dispatch
// - �Լ��� ȣ���ϴ� �� ����ǥ�� �޾� ���� - tag dispatch
// - C++17 ���Ŀ���
//   �����Ϸ��� ���ǿ� ���� �ʴ� �ڵ带 �����ϴ� if constexpr�� ���
// - C++20 ���ʹ�
//   concept�� ����Ͽ� ������ ���� �Ǵ��� �� �ִ�.
//------------------------------------------------------------------
// concepts - ���ø� �Լ��� ���ڴ� �ڷ���(�ƴѰ�쵵 �ִ� - non-type template
// parameter)�ε� �� �ڷ����� ������ �׸��� �ǹ̿����� �ۼ��ڰ� �ǵ��� ��������
// compile-time�� �Ǵ��ϱ� ���� C++ ����� ���
// 
// ranges�� concepts�� ����Ͽ� STL�� ���̺귯���� ���ۼ��� ����
// constrained algorithm�̴�.
// �� �˰������ ranges::algorithm�� �ִ�.
//------------------------------------------------------------------
#include <iostream>
#include <ranges>
#include <concepts>
#include <list>
#include "save.h"
#include "STRING.h"
// using namespace std;					// �츮�� �̷��� �ϸ� �ȵȴ�
// constexpr��?
// move semantic

extern bool watching;					// �����Ϸ��� true�� ����

template <class T>
concept �������� = std::is_integral_v<T> or std::is_floating_point_v<T>;

template<�������� T>
T add(T a, T b)
{
	return a + b;
}

int main(){

	// [����] �ѹ��� �ذ��� add�� �����϶�
	std::cout << add<int>(1, 2) << std::endl;
	std::cout << add<float>(1, 2) << std::endl;
	std::cout << add<STRING>(STRING("2025��"), STRING("6�� 17��")) << std::endl;

	save("main.cpp");
}