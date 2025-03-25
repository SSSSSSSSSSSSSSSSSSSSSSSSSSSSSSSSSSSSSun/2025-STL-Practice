//------------------------------------------------------------------
// 2025 STL ȭ56��78	3�� 25�� ȭ����					(4�� 1��)
//------------------------------------------------------------------
// �����Ҵ�� SMART POINTER - RAII
//------------------------------------------------------------------
// VS ���� - 17.13 �̻�
// RELEASE / X64, C++���ǥ�� - /STD::C++LATEST, SDL �˻� - �ƴϿ�
#INCLUDE <IOSTREAM>
#INCLUDE <FSTREAM>
#INCLUDE <ALGORITHM>
#INCLUDE "SAVE.H"
// USING NAMESPACE STD;			// �츮�� �̷��� �ϸ� �ȵȴ�
// CONSTEXPR��?

//------------------------------------------------------------------
// 1. STACK
// 2. DATA
// 3. FREE-STORE
// 1,2���� 3���� ����	- �޸� ũ�⸦ ���� ������ �� �ִ°�
// 1���� 2���� ����		- �޸� ũ�Ⱑ �󸶳� ū��
// 
// ���� �ð� �̰� ���� �� �����ϰ� SMART POINTER�� ���� - �� RAII�� �߿��Ѱ�
//------------------------------------------------------------------
// [����] "MAIN.CPP"�� ���� �߿� �ҹ��ڸ� ��� �빮�ڷ� �ٲ� "MAIN UPPER.CPP"�� �����Ͻÿ�
//------------------------------------------------------------------



INT MAIN()
{
	STD::IFSTREAM IN{ "MAIN.CPP" };
	IF (NOT IN)
		RETURN -1557;

	STD::OFSTREAM OUT{ "MAIN UPPER.CPP" };
	
	STD::TRANSFORM(STD::ISTREAMBUF_ITERATOR<CHAR>(IN), {},
		STD::OSTREAMBUF_ITERATOR<CHAR>(OUT),
		[](CHAR C) { RETURN TOUPPER(C); });
	
	SAVE("MAIN.CPP");
}