//------------------------------------------------------------------
// string.h - std::string�� ������ Ŭ�����̴�.
//			  STL�� container�� ������ �� �ְ� �ڵ��� ������.
//																2025. 04. 08 ����
// >> ������													2025. 05. 01
// > ������														2025. 05. 08																
// being(), end()												2025. 05. 13
// ������ �ݺ��ڴ� �ݵ�� Ŭ������ ����							2025. 05. 13
// �ݺ��ڵ� �翬�� Ŭ������ �ڵ��ؾ� �Ѵ�						2025. 05. 15
//																2025. 05. 20
//------------------------------------------------------------------

#pragma once
#include <memory>
#include <iostream>

class STRING_Iterator {
public:	// ǥ�� �ݺ��ڴ� ���� �ټ����� ������ ����� �� �־�� �Ѵ�
	using difference_type = ptrdiff_t;
	using value_type = char;
	using pointer = char*;
	using reference = char&;
	using iterator_category = std::random_access_iterator_tag;
	
public:
	STRING_Iterator() = default;
	explicit STRING_Iterator(char* p) : p{ p } {};

	// �ݺ��ڶ�� �ּ��� ���� ����� �����ؾ���
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

	// ���� �ݺ��ڰ� �ǰ�ʹ�					2025. 05. 20

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


// �ݺ��� �����
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
														// ������ ���� ��¿ �� ����

	STRING(const char* in);
	

	// ��������� �����Ҵ翬����

	STRING(const STRING& origin);						// 2025. 04. 08
	STRING& operator= (const STRING& other);			// 2025. 04. 08


	// �̵������� �̵��Ҵ翬����						// 2025. 04. 10.
	STRING(STRING&&);
	STRING& operator=(STRING&&);

	// 2024. 4. 22. ���迬���ڵ�
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
														// 2025. 05. 01. �߰�

	static size_t szGlobalID;							// 2025. 04. 08
	
	// ������ �����ϱ� ���� ���� �߰�					// 2025. 04. 08
};
