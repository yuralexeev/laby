#include <iostream>
#include <cstring>
#include <Windows.h>
using namespace std;
int main()

{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	bool minus = false, is16Digit;
	char ch;
	long long chislo = 0;
	const int Len = 11;
	char InputString[Len]{ '\0' };//си-строка, но почему 11?
	short int ostatok, i;
	//First part__
	//строку преобразуем в число
	cout << "\n\tВведите 16-ичное целое со знаком: ";
	//Первый символ может быть знак
	cin.get(ch);
	minus = ch == '-';
	i = 0;
	if (ch == '-' || ch == '+')
	{
		//формируем строку для контрольного вывода
		InputString[i++] = ch;
		cin.get(ch);//читаем цифру
	}
	cout << "\n\tПреобразование числа в строку:";
	short int zifra;//десятичный эквивалент введенного символа
	//пока поступают символы цифр
	is16Digit = ((ch >= '0' && ch <= '9') || (ch>='a'&&ch<='f') || (ch>='A'&&ch<='F'));
	while (is16Digit)
	{
		//обработка каждого символа цифры 16-СС
		InputString[i++] = ch;//формируем строку
		//символ преобразуем в число
		if (ch >= '0' && ch <= '9') zifra = ch - 48;//почему 48?
		if (ch >= 'a' && ch <= 'f') zifra = ch - 55;
		if (ch >= 'A' && ch <= 'F') zifra = ch - 87;
		//Число умножить на основание системы счисления
		//и прибавить значение цифры(схема Горнера)
		chislo = chislo * 16 + zifra;
		//контрольный вывод
		cout << "\n\tсимвол- " << ch << ", цифра - " << zifra << ", " << " - число " << chislo;
		cin.get(ch);
		is16Digit = ((ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'f') || (ch >= 'A' && ch <= 'F'));

	}
	//Добавим знак
	if (minus) chislo = -chislo;
	//вывод результата первой части
	cout << "\nРезультат" << "\n\tНа входе строка16: " << InputString << "\n\tНа выходе число10: " << chislo;

	//Second part___
	//целое число преобразуем в строку
	char OutputString[Len]{};
	cout << "\n\nОбратное преобразование: Число10 в строку16";
	cout << "\n\nНа входе число: " << chislo;
	minus = chislo < 0;
	chislo = abs(chislo);
	//Цифры числа получаем, начиная с младшего разряда
	i = 0;
	do {
		//остаток от деления есть очередная цифра
		ostatok = chislo % 16;
		//Частное есть следующее число
		chislo = chislo / 16;

	}
}
