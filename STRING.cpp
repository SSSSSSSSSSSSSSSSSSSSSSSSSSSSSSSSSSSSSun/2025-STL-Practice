#include <memory>
#include <iostream>
#include <print>
#include <algorithm>
#include <string>
#include "STRING.h"

bool watching{ false };													// 2025. 04. 08.

STRING::STRING()														// 2025. 04. 08.
	: id{ ++szGlobalID }, length {}
{

	if (watching) {
		std::println("[{:8}] {:16}, 자원수 - {:<10}",
			id, "디폴트생성", length, (void*)this, (void*)pStr.get());
		std::println("           메모리 - {:<20}, 자원메모리 - {:<20} ",
			(void*)this, (void*)pStr.get());
	}
}

STRING::~STRING()
{
	if (watching) {
		std::println("[{:8}] {:16}, 자원수 - {:<10}",
			id, "소멸자", length, (void*)this, (void*)pStr.get());
		std::println("           메모리 - {:<20}, 자원메모리 - {:<20} ",
			(void*)this, (void*)pStr.get());
	}
}

STRING::STRING(const char* in)					// [] -> *로 collapsing
	: id{ ++szGlobalID }, length{ strlen(in) }
{
	pStr.reset();
	pStr = std::make_unique<char[]>(length);

	memcpy(pStr.get(), in, length);				// DMA

	if (watching) {
		std::println("[{:8}] {:16}, 자원수 - {:<10}",
			id, "생성자(char *)", length, (void*)this, (void*)pStr.get());
		std::println("           메모리 - {:<20}, 자원메모리 - {:<20} ",
			(void*)this, (void*)pStr.get());
	}
}

STRING::STRING(const STRING& origin)									// 2025. 04. 08.
	: id{ ++szGlobalID }, length{ origin.length }
{
	pStr = std::make_unique<char[]>(length);

	memcpy(pStr.get(), origin.pStr.get(), length);

	if (watching) {
		std::println("[{:8}] {:16}, 자원수 - {:<10}",
			id, "복사생성자", length, (void*)this, (void*)pStr.get());
		std::println("           메모리 - {:<20}, 자원메모리 - {:<20} ",
			(void*)this, (void*)pStr.get());
	}
}

size_t STRING::size() const
{
	return length;
}

size_t STRING::getID() const
{
	return id;
}

STRING_Iterator STRING::begin() const
{
	return pStr.get();			// return &p[0]
}


STRING_Iterator STRING::end() const
{
	return pStr.get() + length;	// return &p[length]
}

STRING_Reverse_Iterator STRING::rbegin() const
{
	return STRING_Reverse_Iterator{ pStr.get() + length };
}

STRING_Reverse_Iterator STRING::rend() const
{
	return pStr.get();
}

STRING& STRING::operator= (const STRING& other)							// 2025. 04. 08.
{
	if (this == &other) {
		return *this;
	}

	length = other.length;

	pStr.release();					// p.reset()과 다른 점?
	pStr = std::make_unique<char[]>(length);

	memcpy(pStr.get(), other.pStr.get(), length);

	if (watching) {
		std::println("[{:8}] {:16}, 자원수 - {:<10}",
			id, "복사할당연산자", length, (void*)this, (void*)pStr.get());
		std::println("           메모리 - {:<20}, 자원메모리 - {:<20} ",
			(void*)this, (void*)pStr.get());
	}

	return *this;
}

STRING::STRING(STRING&& other)												// 2025. 04. 10.
	: id {++szGlobalID}, length {other.length}
{
	pStr.reset(other.pStr.release());

	other.length = 0;

	if (watching) {
		std::println("[{:8}] {:16}, 자원수 - {:<10}",
			id, "이동생성자", length, (void*)this, (void*)pStr.get());
		std::println("           메모리 - {:<20}, 자원메모리 - {:<20} ",
			(void*)this, (void*)pStr.get());
	}
}


STRING& STRING::operator=(STRING&& other)									// 2025. 04. 10.
{
	if (this == &other) {
		return *this;
	}

	length = other.length;

	pStr.release();
	pStr.reset(other.pStr.release());

	other.length = 0;

	if (watching) {
		std::println("[{:8}] {:16}, 자원수 - {:<10}",
			id, "이동할당연산자", length, (void*)this, (void*)pStr.get());
		std::println("           메모리 - {:<20}, 자원메모리 - {:<20} ",
			(void*)this, (void*)pStr.get());
	}

	return *this;
}

bool STRING::operator==(const STRING& rhl) const
{
	return std::equal(&pStr[0], &pStr[length], &rhl.pStr[0], &rhl.pStr[rhl.length]);
}

bool STRING::operator<(const STRING& rhl) const
{
	return std::lexicographical_compare(pStr.get(), pStr.get() + length,
		rhl.pStr.get(), rhl.pStr.get() + length);
}

std::ostream& operator<< (std::ostream& os, const STRING& str)
{
	for (int i = 0; i < str.length; ++i) {
		os << str.pStr[i];
	}
	return os;
}

std::istream& operator>> (std::istream& is, STRING& str)
{
	std::string s;
	is >> s;
	str.length = s.length();
	str.pStr.release();
	str.pStr = std::make_unique<char[]>(str.length);
	memcpy((char*)str.pStr.get(), s.data(),str.length);
	return is;
}



size_t STRING::szGlobalID{};											// 2025. 04. 08