#include "Programmer.h"

void Programmer::show()
{
	Employee::show();
	cout << "I am programmer" << '\n';
}

void Programmer::input()
{
	cout << "I am programmer" << '\n';
	Employee::input();

	cout << "Enter programming language: ";
	getline(cin, m_programmingLanguage);

}