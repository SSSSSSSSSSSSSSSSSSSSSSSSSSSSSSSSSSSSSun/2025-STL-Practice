//------------------------------------------------------------------
// string.h - std::string과 유사한 클래스이다.
//			  STL의 container로 동작할 수 있게 코딩해 나간다.
//																2025. 04. 08 시작
//------------------------------------------------------------------

#pragma once
#include <memory>
#include <iostream>

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
	bool operator==(const STRING& other) const;

	size_t size() const;
	size_t getID() const;
private:
	size_t length;
	std::unique_ptr<char[]> pStr;
	size_t id;											// 2025. 04. 08										

	friend std::ostream& operator<< (std::ostream& os, const STRING& str);

	static size_t szGlobalID;							// 2025. 04. 08
	
	// 관찰을 제어하기 위한 변수 추가					// 2025. 04. 08
};
