#include <iostream>
#include <fstream>
#include <string>

void file_insert(std::string path, int pos, std::string str);

int main() {
	setlocale(LC_ALL, "Russian");
	int n;
	std::string path = "file.txt";

	// ����� fstream
	/*std::fstream file;	// ��������� � ���������, � ����������
	// ��� fstream ������������ ������ std::ios::in
	file.open(path, std::ios::in | std::ios::app);	// << | >> - ������� "���"

	if (file.is_open()) {
		std::cout << "���� ������.\n";
		// ������ � ����
		file << "Bye world!\n";
		std::cout << "������ ��������.\n";

		file.seekg(0, std::ios::beg); // ����������� ������� ��� ���������� � ������ �����, ��� "0" - ���������� �����

		// ���������� �� �����
		std::cout << "���������� �����:\n";
		char sym;
		while (file.get(sym))
			std::cout << sym;
	}
	else
		std::cout << "������ ������� �����.\n";

	// seekg - seek get pointer (����� ������ ��� ����������, ���������� ������)
	// seekp - seek put pointer (����� ������ ��� ������, ���������� ������) - ������ �� ������������
	
	// ����� ������� ������� ������� � �����
	// fs.tellg();
	// fs.tellp();
	file.close();*/

	// ������� "������ � ����"
	/*std::cout << "������� ������ -> ";
	std::string str;
	getline(std::cin, str);
	std::cout << "������� ������� -> ";
	std::cin >> n;
	file_insert(path,n,str);*/

	// ������. ���� �� �����
	std::cout << "������. ���� �� �����:\n";
	std::ifstream in;
	in.open("date.txt");

	if (in.is_open()) {
		int day, month, year;
		std::string tmp;
		getline(in, tmp);
		day = stoi(tmp);	// stoi(tmp.substr(0, tmp.find('.'))). ����� ������ ���, �.� stoi ���� ��� ����� �� �������(� ����� ������ ".")
		std::cout << "����: " << day << "\n";

		month = stoi(tmp.substr(tmp.find('.') + 1));
		std::cout << "�����: " << month << "\n";

		year = stoi(tmp.substr(tmp.rfind('.') + 1));
		std::cout << "���: " << year << "\n";
	}
	else
		std::cout << "������ �������� �����.\n\n";

	in.close();

	return 0;
}
// ������� "������ � ����"
void file_insert(std::string path, int pos, std::string str) {
	// ��� 1. �������� ���������� ����� � ������
	std::ifstream in;
	in.open(path);	// �� ��������� std::ios::in, ������� ������ �� ����� ����� path
	std::string tmp;
	
	if (in.is_open()) {
		char sym;
		while (in.get(sym))
			tmp += sym;
	}
	in.close();

	// std::cout << tmp; // ������������� ��������
	
	// ��� 2. ��������� ���������� str � ������ tmp
	tmp.insert(pos, str);

	// ��� 3. �������� ���������� ����� �� ������ tmp
	std::ofstream out;
	out.open(path);

	if (out.is_open())
		out << tmp;
	out.close();
}