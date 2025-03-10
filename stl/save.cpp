#include "save.h"

//----------
void save(std::string_view fileName)
//----------
{
	// fileName�� �б���� ����
	std::ifstream in{ fileName.data() };		// RAII
	if (not in) {
		std::cout << fileName << "�� �� �� �����ϴ�" << std::endl;
		exit(20250306);
	}

	// ������� ������ ������ ����
	std::string nameForSave{ "2025 1 STL ȭ56��78 ��������.txt" };
	std::ofstream out{ nameForSave , std::ios::app };

	// �����ߴٰ� ȭ�� ���

	auto size = std::filesystem::file_size(fileName);
	std::cout << nameForSave << "�� " << fileName << "�� ���ٿ����ϴ�. - "
		<< size << "Bytes" << std::endl;

	// ������ �ð��� ���Ͽ� �������
	auto now = std::chrono::system_clock::now();				// time_point�� ��´�. epoch
	auto utc = std::chrono::system_clock::to_time_t(now);		// UTC �ð����� ����
	auto lt = std::localtime(&utc);							// �����޷� �ð�����
	auto old = out.imbue(std::locale("ko_KR"));

	out << '\n' << '\n';
	out << "=================================================" << '\n';
	out << "������ �ð�: " << std::put_time(lt, "%c %A") << '\n';
	out << "=================================================" << '\n';
	out << '\n';

	out.imbue(old);			// �� locale�� ����

	// ���� ���Ͽ� �ִ� ��� ������ �о� �� ���Ͽ� ���ٿ� ����
	std::vector<char> v(size);
	std::copy(std::istreambuf_iterator{ in }, {}, std::ostreambuf_iterator{ out });
}
