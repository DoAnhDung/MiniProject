#include "Manager.h"

Manager::Manager()
	: Employee{}
{
}

Manager::Manager(int id, string name, int salary, int age)
	: Employee{ id, name, salary, age }
{
}

void Manager::input()
{
	cout << "I am manager" << '\n';

	Employee::input();

	cout << "Enter years of experience: " << '\n';
	cin >> m_yoe;

	cin.ignore(100, '\n');
}

void Manager::show()
{
	Employee::show();
	cout << "I am manager" << '\n';
}