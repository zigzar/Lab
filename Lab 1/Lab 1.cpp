#include <iostream>
#include <Windows.h>
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
	short i, intType;
	DoubleUnion du;
	FloatUnion fu;
	double check;
	bool err = true;
	setlocale(0, "");

	while (err == true)
	{
		cout << "Выберите тип (введите натуральное число от 1 до 3):\n 1 - int\n 2 - short int\n 3 - unsigned int\n 4 - double\n";
		cin >> intType;
		if (intType < 1 || intType > 5)
		{
			cout << "Тип выбран некорректно. Мой 8-летний брат знает, что такое натуральное число от 1 до 3, А ТЫ - НЕТ!\n";
			continue;
		}
		if (intType >= 1 || intType <= 5)
		{
			if (intType == 1)
			{
				int a1;
				cout << "Введите число int\n";
				cin >> check;

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
			}
			if (intType == 2)
			{
				short a2;
				cout << "Введите число short int\n";
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
				};
			}
			if (intType == 3)
			{
				unsigned int a3;
				cout << "Введите число unsigned int\n";
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

			}
			if (intType == 4)
			{
				err = false;
				cout << "Введите число double\n";
				cin >> du.d;
				i = 64;
				bool r;
				r = du.a[0] & (1U << --i);
				cout << r << " ";
				SetConsoleTextAttribute(h, 14);
				for (short n = 0; n <= 1; ++n)
				{
					for (--i; i >= 0; --i)
					{
						r = du.a[n] & (1U << i);
						if (i % 4 == 0)
						{
							cout << r << " ";
						}
						else
						{
							cout << r;
						}
						if (i == 52)
						{
							SetConsoleTextAttribute(h, 9);
						}
					};
				};
				SetConsoleTextAttribute(h, 7);
			};
			if (intType == 5)
			{
				err = false;
				cout << "Введите число float\n";
				cin >> fu.f;
				i = 64;
				bool r;
				r = fu.a & (1U << --i);
				cout << r << " ";
				SetConsoleTextAttribute(h, 14);
				for (--i; i >= 0; --i)
					{
						r = fu.a & (1U << i);
						if (i % 4 == 0)
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

		};
	};
}
