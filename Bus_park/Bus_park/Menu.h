#pragma once
#include "BusPark.h"
#include <iostream>
#include <conio.h>
#include"Get.h"
using namespace std;

#define ESC   27
class Menu
{
public:
	Menu();

	void print_menu();
	~Menu();

private:

	void print_menu2();
	void print_menu1();
};

Menu::Menu()
{
}

void Menu::print_menu()
{
	Get get;
	BusPark My;
	cout << "\nInitial formation of the list.\n";

	char key = ' ';
	while (key != ESC)
	{
		
		/*system("cls");*/
		My.NewBus();
		std::cout << "(Press \"Esc\" to exit input.)\n";
		/*cin >> key;*/
		key = _getch();
		
	}
	while (true)
	{
		/* system("cls");*/
		print_menu1();


		char item;
		cin >> item;

		switch (item)
		{
			int number;
		case'1':
			cout << "Enter bus number.\n>";
			number = get._int();
			try {
				My.In_Out(number);
			}
			catch (const std::exception& exc) {
				cout << exc.what() << endl;
				system("pause");
			}
			break;
		case'2':
			cout << "Enter bus number.\n>";
			number = get._int();
			try {
				My.Out_In(number);
			}
			catch (const std::exception& exc) {
				cout << exc.what() << endl;
				system("pause");
			}
			break;
		case'3':
			char ch;
			print_menu2();
			cin >> ch;
			if (ch=='1'|| ch == '2')
				My.PrintBusList(ch);
			else
				cout << "Error no item!";

				system("pause");
			break;
		case'4':
			exit(0);
			break;
		default:
			break;
		}
	}
}

inline void Menu::print_menu2()
{
	cout << "\n1) Buses in the park."
		<< "\n2) Buses on route.\n>";
}

inline void Menu::print_menu1()
{
	cout << "\n1) Departure bus from the park."
		<< " \n2) Bus entrance from the park."
		<< "\n3) Data output request.\n"
		<< "4) Exit\n>";
}

Menu::~Menu()
{
}
