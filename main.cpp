//------------------------------------------------------------------
// 2025 STL ȭ56��78	3�� 6�� �����					(1�� 2��)
//------------------------------------------------------------------
// ���� ���� �ڷḦ ó���ϱ�
//------------------------------------------------------------------
// VS ���� - 17.13 �̻�
// Release / x64, C++���ǥ�� - /std::c++latest, SDL �˻� - �ƴϿ�
#include <iostream>
#include <random>
#include <print>
#include "save.h"
// using namespace std;			// �츮�� �̷��� �ϸ� �ȵȴ�
// 
// [����] ���� int 1000���� �޸𸮿� �����϶�
// ���� ū ���� ã�� ȭ�鿡 ����϶�

std::default_random_engine dre;
std::uniform_int_distribution uid{ 0,9999999 };

int main()
{
	for (int i = 0; i < 1000; ++i) {
		std::print("{:8}", uid(dre));
	}

	save("main.cpp");
}