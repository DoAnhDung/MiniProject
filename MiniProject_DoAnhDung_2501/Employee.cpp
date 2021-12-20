#include "Employee.h"

void Employee::show()
{
	cout << m_id << " " << m_name << " " << m_email << " " << m_salary << " " << m_age <<'\n';
}

void Employee::input()
{
	cout << "Enter id: ";
	cin >> m_id;

	cin.ignore(100, '\n');

	cout << "Enter name: ";
	getline(cin, m_name);

	cout << "Enter email: ";
	getline(cin, m_email);

	cout << " Enter salary:";
	cin >> m_salary;

	cout << " Enter Age:";
	cin >> m_age;
}

string Employee::getName()
{
	return m_name;
}

int Employee::getSalary()
{
	return m_salary;
}

int Employee::getAge()
{
	return m_age;
}
