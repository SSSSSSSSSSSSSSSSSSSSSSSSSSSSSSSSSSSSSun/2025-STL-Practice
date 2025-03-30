//------------------------------------------------------------------
// 2025 STL ȭ56��78	3�� 27�� �����					(4�� 2��)
//------------------------------------------------------------------
// Callable type - ȣ�Ⱑ���� Ÿ��
// 1. �Լ�
//------------------------------------------------------------------
// VS ���� - 17.13 �̻�
// Release / x64, C++���ǥ�� - /std::c++latest, SDL �˻� - �ƴϿ�
#include <iostream>
#include <random>
#include <array>
#include <memory>
#include <print>
#include <ranges>
#include <algorithm>
#include <chrono>
#include "save.h"
// using namespace std;			// �츮�� �̷��� �ϸ� �ȵȴ�
// constexpr��?

// [����] ���� int 1000������ �޸𸮿� ��������.
// ���� int ���� ������ [0, 10'000'000) ===> 0���� 9'999'999���� ���� ������
// C++ ����� sort�� ����Ͽ� ������������ �����϶�
// ������ ����� �տ��� ���� 1000���� ȭ�鿡 ����϶�

std::default_random_engine dre;

bool ascendingOrder(const int a, const int b)
{
	return a < b;
}

int main()
{
	std::uniform_int_distribution uid{ 0,9'999'999 };
	std::unique_ptr<std::array<int, 10'000'000>> upArray = std::make_unique<std::array<int, 10'000'000>>();

	{
		for (int& num : *upArray) {
			num = uid(dre);
		}
		// ���Ŀ� �ɸ��� �ð� ����
		auto b = std::chrono::high_resolution_clock::now();						// �����ġ ����
		std::sort(upArray->begin(), upArray->end(), ascendingOrder);			// ����Ʈ ���� operator <
		auto e = std::chrono::high_resolution_clock::now();						// �����ġ ��

		/*for (int num : *upArray | std::ranges::views::take(3000)) {
			std::print("{:8}", num);
		}*/
		std::cout << "����ð�(ms) - " << std::chrono::duration_cast<std::chrono::milliseconds>(e - b) << '\n';
	}

	{	// ������������ ����
		for (int& num : *upArray) {
			num = uid(dre);
		}
		// ���Ŀ� �ɸ��� �ð� ����
		auto b = std::chrono::high_resolution_clock::now();						// �����ġ ����
		std::sort<std::array<int,10'000'000>::iterator>(upArray->begin(), upArray->end(),[](const int a, const int b) {
			return a > b;
			});
		auto e = std::chrono::high_resolution_clock::now();						// �����ġ ��

		/*for (int num : *upArray | std::ranges::views::take(3000)) {
			std::print("{:8}", num);
		}*/
		std::cout << "����ð�(ms) - " << std::chrono::duration_cast<std::chrono::milliseconds>(e - b) << '\n';
	}

	save("main.cpp");
}