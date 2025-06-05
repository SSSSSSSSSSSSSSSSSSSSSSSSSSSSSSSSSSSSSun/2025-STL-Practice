//------------------------------------------------------------------
// 2025 STL ȭ56��78	5�� 29�� �����							(13�� 1��)
// 6�� 19�� ����� 15�� 2�� - �⸻ ����
//------------------------------------------------------------------
// VS ���� - 17.13 �̻�
// Release / x64, C++���ǥ�� - /std::c++latest, SDL �˻� - �ƴϿ�
//------------------------------------------------------------------
// Unordered Associative Containers - hash ����
//------------------------------------------------------------------
#include <iostream>
#include <unordered_set>
#include <print>
#include "save.h"
#include "STRING.h"
// using namespace std;					// �츮�� �̷��� �ϸ� �ȵȴ�
// constexpr��?
// move semantic

extern bool watching;					// �����Ϸ��� true�� ����

template <>
struct std::hash<STRING> {
	size_t operator()(const STRING& s) const {
		//std::string str(s.begin(), s.end());
		return std::hash<std::string>{}(std::string(s.begin(), s.end()));
	}
};

int main()
{

	std::unordered_set<STRING, std::hash<STRING>> us{"1", "22", "333", "4444", "55555"};

	for (const STRING& s : us) {
		std::cout << s << '\n';
	}

	// unordered_set�� �޸𸮸� ȭ�鿡 ����Ѵ�.

	while (true) {
		for (size_t bc = 0; bc < us.bucket_count(); ++bc) {
			std::print("[{:>3}]", bc);
			for (auto i = us.begin(bc); i != us.end(bc); ++i) {
				std::print(" -> {:}", std::string{ i->begin(), i->end() });
			}

			std::cout << '\n';
		}

		std::cout << "�߰��� STRING - ";
		STRING s;
		std::cin >> s;

		us.insert(s);
	}
	save("main.cpp");
}