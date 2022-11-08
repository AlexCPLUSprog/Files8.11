#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include "windows.h"

void file_insert(std::string path, int pos, std::string str);

const int tick = 100;
int timer = 0;

int main() {
	setlocale(LC_ALL, "Russian");
	int n;
	std::string path = "file.txt";

	// Про проекты (projects)
	// для понга и галаги
	/*char key;
	while (true) {
		if (_kbhit()) {				// keyboard hit
			key = _getch();
			switch (key) {
			case 'A': case 'a':
				std::cout << "left\n";
				break;
			case 'D': case 'd':
				std::cout << "right\n";
				break;
			}
		}		
		Sleep(tick);
		timer += tick;
		if (timer >= 1000) {
			std::cout << ".\n";
			timer = 0;
		}
	}*/
	//
	std::cout << "Введите число: ";
	std::cin >> n;
	system("cls");	// полная очистка консоли
	std::cout << "Число = " << n << "\n";
	system("pause"); // приостановка приложения


	// Класс fstream
	/*std::fstream file;	// позволяет и считывать, и записывать
	// для fstream используется только std::ios::in
	file.open(path, std::ios::in | std::ios::app);	// << | >> - битовое "или"

	if (file.is_open()) {
		std::cout << "Файл открыт.\n";
		// Запись в файл
		file << "Bye world!\n";
		std::cout << "Данные записаны.\n";

		file.seekg(0, std::ios::beg); // Перемещение курсора для считывания в начало файла, где "0" - количество шагов

		// Считывание из файла
		std::cout << "Содержимое файла:\n";
		char sym;
		while (file.get(sym))
			std::cout << sym;
	}
	else
		std::cout << "Ошибка запуска файла.\n";

	// seekg - seek get pointer (найти курсор для считывания, перемещает курсор)
	// seekp - seek put pointer (найти курсор для записи, перемещает курсор) - обычно не используется
	
	// Вывод текущей позиции курсора в файле
	// fs.tellg();
	// fs.tellp();
	file.close();*/

	// Задание "Запись в файл"
	/*std::cout << "Введите строку -> ";
	std::string str;
	getline(std::cin, str);
	std::cout << "Введите позицию -> ";
	std::cin >> n;
	file_insert(path,n,str);*/

	// Задача. Дата из файла
	/*std::cout << "Задача. Дата из файла:\n";
	std::ifstream in;
	in.open("date.txt");

	if (in.is_open()) {
		int day, month, year;
		std::string tmp;
		getline(in, tmp);
		day = stoi(tmp);	// stoi(tmp.substr(0, tmp.find('.'))). Пишем просто тмп, т.к stoi ищет все цифры до символа(в нашем случае ".")
		std::cout << "День: " << day << "\n";

		month = stoi(tmp.substr(tmp.find('.') + 1));
		std::cout << "Месяц: " << month << "\n";

		year = stoi(tmp.substr(tmp.rfind('.') + 1));
		std::cout << "Год: " << year << "\n";
	}
	else
		std::cout << "Ошибка открытия файла.\n\n";

	in.close();*/

	return 0;
}
// Задание "Запись в файл"
void file_insert(std::string path, int pos, std::string str) {
	// Шаг 1. Копируем содержимое файла в строку
	std::ifstream in;
	in.open(path);	// по умолчанию std::ios::in, поэтому ничего не пишем после path
	std::string tmp;
	
	if (in.is_open()) {
		char sym;
		while (in.get(sym))
			tmp += sym;
	}
	in.close();

	// std::cout << tmp; // промежуточная проверка
	
	// Шаг 2. Вставляем содержимое str в строку tmp
	tmp.insert(pos, str);

	// Шаг 3. Заменяем содержимое файла на строку tmp
	std::ofstream out;
	out.open(path);

	if (out.is_open())
		out << tmp;
	out.close();
}