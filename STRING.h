//------------------------------------------------------------------
// string.h - std::string�� ������ Ŭ�����̴�.
//			  STL�� container�� ������ �� �ְ� �ڵ��� ������.
//																2025. 04. 08 ����
//------------------------------------------------------------------

#pragma once
#include <memory>
#include <iostream>

class STRING {
public:
	STRING();											// 2025. 04. 08
	~STRING();											// 2025. 04. 08
														// ������ ���� ��¿ �� ����

	STRING(const char* in);
	

	// ��������� �����Ҵ翬����

	STRING(const STRING& origin);						// 2025. 04. 08
	STRING& operator= (const STRING& other);			// 2025. 04. 08


	// �̵������� �̵��Ҵ翬����						// 2025. 04. 10.
	STRING(STRING&&);
	STRING& operator=(STRING&&);

	// 2024. 4. 22. ���迬���ڵ�
	bool operator==(const STRING& other) const;

	size_t size() const;
	size_t getID() const;
private:
	size_t length;
	std::unique_ptr<char[]> pStr;
	size_t id;											// 2025. 04. 08										

	friend std::ostream& operator<< (std::ostream& os, const STRING& str);

	static size_t szGlobalID;							// 2025. 04. 08
	
	// ������ �����ϱ� ���� ���� �߰�					// 2025. 04. 08
};
