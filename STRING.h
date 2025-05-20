//------------------------------------------------------------------
// string.h - std::string과 유사한 클래스이다.
//			  STL의 container로 동작할 수 있게 코딩해 나간다.
//																2025. 04. 08 시작
// >> 연산자													2025. 05. 01
// > 연산자														2025. 05. 08																
// being(), end()												2025. 05. 13
// 역방향 반복자는 반드시 클래스로 제공							2025. 05. 13
// 반복자도 당연히 클래스로 코딩해야 한다						2025. 05. 15
//																2025. 05. 20
//------------------------------------------------------------------

#pragma once
#include <memory>
#include <iostream>

class STRING_Iterator {
public:	// 표준 반복자는 다음 다섯가지 물음에 대답할 수 있어야 한다
	using difference_type = ptrdiff_t;
	using value_type = char;
	using pointer = char*;
	using reference = char&;
	using iterator_category = std::random_access_iterator_tag;
	
public:
	STRING_Iterator() = default;
	explicit STRING_Iterator(char* p) : p{ p } {};

	// 반복자라면 최소한 다음 기능을 제공해야함
	char& operator*() const {
		return *p;
	}

	pointer operator->() const {
		return p;
	}

	bool operator==(const STRING_Iterator& rhs) const {
		return p == rhs.p;
	}

	STRING_Iterator operator++() {
		++p;
		return *this;
	}

	// 랜덤 반복자가 되고싶다					2025. 05. 20

	difference_type operator-(const STRING_Iterator& rhs) const {
		return p - rhs.p;
	}

	STRING_Iterator operator--() {
		--p;
		return *this;
	}

	STRING_Iterator operator+(difference_type n) const {
		return STRING_Iterator(p + n);
	}

	STRING_Iterator operator-(difference_type n) const {
		return STRING_Iterator(p - n);
	}

	auto operator<=>(const STRING_Iterator& rhs) const {
		return p <=> rhs.p;
	}

private:
	char* p {};
};


// 반복자 어댑터
class STRING_Reverse_Iterator {
public:
	STRING_Reverse_Iterator() = delete;
	STRING_Reverse_Iterator(char* p) : p{ p } {};

	char& operator*() const{
		return *(p-1);
	}
	char* operator++() {
		--p;
	}

	bool operator==(const STRING_Reverse_Iterator& rhs) const {
		return p == rhs.p;
	}

private:
	char* p;
};

class STRING {
public:
	STRING();											// 2025. 04. 08
	~STRING();											// 2025. 04. 08
														// 관찰을 위해 어쩔 수 없이

	STRING(const char* in);
	

	// 복사생성과 복사할당연산자

	STRING(const STRING& origin);						// 2025. 04. 08
	STRING& operator= (const STRING& other);			// 2025. 04. 08


	// 이동생성과 이동할당연산자						// 2025. 04. 10.
	STRING(STRING&&);
	STRING& operator=(STRING&&);

	// 2024. 4. 22. 관계연산자들
	bool operator==(const STRING& rhl) const;
	bool operator<(const STRING& rhl) const;			// 2025. 05. 08.

	size_t size() const;
	size_t getID() const;

	// begin(), end()
	STRING_Iterator begin() const;
	STRING_Iterator end() const;
	STRING_Reverse_Iterator rbegin() const;
	STRING_Reverse_Iterator rend() const;
private:
	size_t length;
	std::unique_ptr<char[]> pStr;
	size_t id;											// 2025. 04. 08										

	friend std::ostream& operator<< (std::ostream& os, const STRING& str);

	friend std::istream& operator>> (std::istream& is, STRING& str);
														// 2025. 05. 01. 추가

	static size_t szGlobalID;							// 2025. 04. 08
	
	// 관찰을 제어하기 위한 변수 추가					// 2025. 04. 08
};
