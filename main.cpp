//------------------------------------------------------------------
// 2025 STL 화56목78	4월 1일 화요일				(5주 1일)
// 중간고사	(30) - 4월 24일 목요일
// 과제		(30) - 4월 10일 설명
//------------------------------------------------------------------
// Callable
//------------------------------------------------------------------
// VS 버전 - 17.13 이상
// Release / x64, C++언어표준 - /std::c++latest, SDL 검사 - 아니오
#include <iostream>
#include <string>
#include <random>
#include <memory>
#include <array>
#include <fstream>
#include "save.h"
// using namespace std;			// 우리는 이렇게 하면 안된다
// constexpr란?

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

// [문제] Dog 10만마리를 다음과 같이 파일 "Dog 십만마리"에 저장하였다.
// 파일은 다음 코드로 열었다.
//		std::ofstream out("Dog 십만마리");
// 
// 
// Dog 객체는 class Dog의 friend operator<< 를 사용하여 저장하였다.
//
// [문제] 이 파일에는 정확하게 10만개의 Dog 객체가 저장되어 있다.
// 파일에 저장된 Dog 객체를 모두 읽어 메모리에 저장하라.
// 제일 마지막 객체의 정보를 화면에 출력하고 답지에도 출력내용을 적어라.
// 메모리에 저장된 Dog 객체를 멤버 name 길이 기준 오름차순으로 정렬하라.
// 정렬된 Dog 객체를 앞에서 부터 1000개를 화면에 출력하라.

std::array<Dog, 10'0000 > dogs;

int main()
{
	std::ifstream in("Dog 십만마리");

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