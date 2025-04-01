//------------------------------------------------------------------
// 2025 STL ȭ56��78	4�� 1�� ȭ����				(5�� 1��)
// �߰����	(30) - 4�� 24�� �����
// ����		(30) - 4�� 10�� ����
//------------------------------------------------------------------
// Callable
//------------------------------------------------------------------
// VS ���� - 17.13 �̻�
// Release / x64, C++���ǥ�� - /std::c++latest, SDL �˻� - �ƴϿ�
#include <iostream>
#include <string>
#include <random>
#include <memory>
#include <array>
#include <fstream>
#include "save.h"
// using namespace std;			// �츮�� �̷��� �ϸ� �ȵȴ�
// constexpr��?

std::default_random_engine dre;
std::uniform_int_distribution<int> uidName{ 'a','z' };
std::uniform_int_distribution<int> uidNameLength{ 3, 30 };
std::uniform_int_distribution<int> uidId{};

class Dog {
public:
	Dog() {
		int nNameLength = uidNameLength(dre);
		for (int i = 0; i < nNameLength; ++i) {
			name += uidName(dre);
		}
		id = uidId(dre);
	}

	friend std::ostream& operator<<(std::ostream& os, const Dog& dog) {
		return os << dog.id << " " << dog.name << " ";
	}

	void setDog(int inputId, std::string inputName) {
		name = inputName;
		id = inputId;
	}
private:
	std::string name;
	int id;
};

// [����] Dog 10�������� ������ ���� ���� "Dog �ʸ�����"�� �����Ͽ���.
// ������ ���� �ڵ�� ������.
//		std::ofstream out("Dog �ʸ�����");
// 
// 
// Dog ��ü�� class Dog�� friend operator<< �� ����Ͽ� �����Ͽ���.
//
// [����] �� ���Ͽ��� ��Ȯ�ϰ� 10������ Dog ��ü�� ����Ǿ� �ִ�.
// ���Ͽ� ����� Dog ��ü�� ��� �о� �޸𸮿� �����϶�.
// ���� ������ ��ü�� ������ ȭ�鿡 ����ϰ� �������� ��³����� �����.
// �޸𸮿� ����� Dog ��ü�� ��� name ���� ���� ������������ �����϶�.
// ���ĵ� Dog ��ü�� �տ��� ���� 1000���� ȭ�鿡 ����϶�.

std::array<Dog, 10'0000 > dogs;

int main()
{
	std::ifstream in("Dog �ʸ�����");

	if (not in) {
		return -1557;
	}
	
	for (int i = 0; i < 10'0000; ++i) {
		int id;
		std::string name;
		in >> id >> name;
		dogs[i].setDog(id, name);
	}

	std::cout << *(dogs.rbegin()) << '\n';



	save("main.cpp");
}