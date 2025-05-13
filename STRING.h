//------------------------------------------------------------------
// string.h - std::string과 유사한 클래스이다.
//			  STL의 container로 동작할 수 있게 코딩해 나간다.
//																2025. 04. 08 시작
// >> 연산자													2025. 05. 01
// > 연산자														2025. 05. 08																
// being(), end()												2025. 05. 13
// 역방향 반복자는 반드시 클래스로 제공							2025. 05. 13
//------------------------------------------------------------------

#pragma once
#include <memory>
#include <iostream>

// 반복자 어댑터
class STRING_Reverse_Iterator {
public:
	STRING_Reverse_Iterator() = delete;
	STRING_Reverse_Iterator(char* p) : p{ p } {};

	char& operator*() const{
		return *(p-1);
	}
	void operator++() {
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
	char* begin() const;
	char* end() const;
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
