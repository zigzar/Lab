#include <iostream>
#include <Windows.h>
using namespace std;

int main()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	short i, intType;
	double check;
	bool err = false;
	setlocale(0, "");

	cout << "Выберите тип:\n 1 - int\n 2 - short int\n 3 - unsigned int\n";
	cin >> intType;
	
	if (intType == 1)
	{
		int a1;
		cout << "Введите число int\n";
		cin >> check;

		if (check >= -signed(2147483648) && check <= 2147483647 && check == int(check))
		{
			a1 = int(check);
		}
		else
		{
			err = true;
		};

		if (err == false)
		{
			i = 32;
			bool r;
			r = a1 & (1U << --i);
			cout << r << " ";
			SetConsoleTextAttribute(h, 14);
			for (--i; i >= 0; --i)
			{
				r = a1 & (1U << i);
				cout << r;
			}
			SetConsoleTextAttribute(h, 7);
		}
	}

	if (intType == 2)
	{
		short a2;
		cout << "Введите число short int\n";
		cin >> check;

		if (check >= -(32768) && check <= 32767 && check == int(check))
		{
			a2 = short(check);
		}
		else
		{
			err = true;
		};

		if (err == false)
		{
			i = 16;
			bool r;
			r = a2 & (1U << --i);
			cout << r << " ";
			SetConsoleTextAttribute(h, 14);
			for (--i; i >= 0; --i)
			{
				r = a2 & (1U << i);
				cout << r;
			}
			SetConsoleTextAttribute(h, 7);
		};
	}
	if (intType == 3)
	{
		unsigned int a3;
		cout << "Введите число unsigned int\n";
		cin >> check;

		if (check >= 0 && check <= 4294967295 && check == unsigned int(check))
		{
			a3 = unsigned int (check);
		}
		else
		{
			err = true;
		};

		if (err == false)
		{
			i = 32;
			bool r;
			SetConsoleTextAttribute(h, 14);
			for (--i; i >= 0; --i)
			{
				r = a3 & (1U << i);
				cout << r;
			}
			SetConsoleTextAttribute(h, 7);
		}
	}

	if (err == true)
	{
		cout << "Ошибка типа: число введено некорректно. Пожалуйста, введите другое число или выберите другую модернизацию типа";
	}
	
}
