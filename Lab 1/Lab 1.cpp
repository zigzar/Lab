#include <iostream>
#include <Windows.h>
#include <cstdlib>
#include <cerrno> 

using namespace std;

/*int getBinary (int a, unsigned short int i, bool isSigned)
{
	bool r;
	if (isSigned == 1)
	{
		r = a & (1U << --i);
		cout << r << " ";
	}
	r = a & (1U << --i);
	cout << r << " ";
	SetConsoleTextAttribute(h, 14);
	for (--i; i >= 0; --i)
	{
		r = a & (1U << i);
		cout << r;
	}
	SetConsoleTextAttribute(h, 7);
	return 0;
}*/

/*int inputCheck(char inp[256])
{
	for (int g = 0; inp[g] != '\0'; g++)
		if (inp[g] < 48 || inp[g]>57 || !(inp[g]==46))
		{
			std::cout << "Ошибка ввода числа. Пожалуйста введите число, используя арабские цифры";
			return false;
		}
	return strtod(inp, NULL);
}*/

union DoubleUnion
{
	double d;
	int a[2];
};
union FloatUnion
{
	float f;
	int a;
};

int main()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	short i;
	int intType;
	DoubleUnion du;
	FloatUnion fu;
	double check;
	bool err = true;
	char input[256];
	setlocale(0, "");

	while (err == true)
	{
		cout << "Объем памяти для Double: " << sizeof(du) << " байт\n";
		cout << "Объем памяти для Float: " << sizeof(fu) << " байта\n\n";
		cout << "Выберите тип (введите натуральное число от 1 до 5 в естественном виде арабскими цифрами):\n 1 - int\n 2 - short int\n 3 - unsigned int\n 4 - double\n 5 - float\n";
		cin >> input;
		intType = atoi(input);
		if (intType < 1 || intType > 5)
		{
			cout << "Тип выбран некорректно. Повторите попытку\n";
		};
		if (intType >= 1 || intType <= 5)
		{
			if (intType == 1)
			{
				int a1;
				cout << "Введите число int в естественном виде арабскими цифрами\n";
				cin >> input;
				check = strtod(input,NULL);
				if (errno == ERANGE)
				{
					cout << "Ошибка допустимых значений";
					return 0;
				}
				if (check >= -signed(2147483648) && check <= 2147483647 && check == int(check))
				{
					a1 = int(check);
					err = false;
				}

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
						if (i % 4 == 0)
						{
							cout << r << " ";
						}
						else
						{
							cout << r;
						}


					}
					SetConsoleTextAttribute(h, 7);
				}
				else cout << "Ошибка типа. Пожалуйста, введите корректное значение или выберите другой тип.\n"; 
			}
			if (intType == 2)
			{
				short a2;
				cout << "Введите число short int в естественном виде арабскими цифрами\n";
				cin >> check;

				if (check >= -(32768) && check <= 32767 && check == int(check))
				{
					a2 = short(check);
					err = false;
				}

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
						if (i % 4 == 0)
						{
							cout << r << " ";
						}
						else
						{
							cout << r;
						}
					}
					SetConsoleTextAttribute(h, 7);
				}
				else cout << "Ошибка типа. Пожалуйста, введите корректное значение или выберите другой тип.\n"; 
			}
			if (intType == 3)
			{
				unsigned int a3;
				cout << "Введите число unsigned int в естественном виде арабскими цифрами\n";
				cin >> check;

				if (check >= 0 && check <= 4294967295 && check == unsigned int(check))
				{
					a3 = unsigned int(check);
					err = false;
				}

				if (err == false)
				{
					i = 32;
					bool r;
					SetConsoleTextAttribute(h, 14);
					for (--i; i >= 0; --i)
					{
						r = a3 & (1U << i);
						if (i % 4 == 0)
						{
							cout << r << " ";
						}
						else
						{
							cout << r;
						}
					}
					SetConsoleTextAttribute(h, 7);
				}
				else cout << "Ошибка типа. Пожалуйста, введите корректное значение или выберите другой тип.\n"; 

			}
			if (intType == 4)
			{
				err = false;
				cout << "Введите число double в естественном виде арабскими цифрами\n";
				cin >> input;
				du.d = strtod(input, NULL);
				i = 64;
				bool r;
				r = du.a[0] & (1U << --i);
				cout << r << " ";
				SetConsoleTextAttribute(h, 14);
				for (--i; i >= 32; --i)
				{
					r = du.a[1] & (1U << i);
					if ((i + 1) % 4 == 0)
					{
						cout << r << " ";
					}
					else
					{
						cout << r;
					}
					if (i == 51)
					{
						SetConsoleTextAttribute(h, 9);
					}
				};
				for (--i; i >= 0; --i)
					{
						r = du.a[0] & (1U << i);
						if ((i+1) % 4 == 0)
						{
							cout << r << " ";
						}
						else
						{
							cout << r;
						}
						if (i == 51)
						{
							SetConsoleTextAttribute(h, 9);
						}
				};
				SetConsoleTextAttribute(h, 7);
			};
			if (intType == 5)
			{
				err = false;
				cout << "Введите число float в естественном виде арабскими цифрами\n";
				cin >> fu.f;
				i = 32;
				bool r;
				r = fu.a & (1U << --i);
				cout << r << " ";
				SetConsoleTextAttribute(h, 14);
				for (--i; i >= 0; --i)
					{
						r = fu.a & (1U << i);
						if ((i+1) % 4 == 0)
						{
							cout << r << " ";
						}
						else
						{
							cout << r;
						}
						if (i == 23)
						{
							SetConsoleTextAttribute(h, 9);
						}
					};
				SetConsoleTextAttribute(h, 7);
			};
		}

	};
}
