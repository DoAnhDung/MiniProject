#pragma once
#include <iostream>
#include <string>

using namespace std;

class Employee
{
protected:
	int m_id{ 0 };
	string m_name;
	string m_email;
	int m_salary{ 0 };
	int m_age{ 0 };
public:
	
	Employee() {};

	Employee(int id, string name, int salary, int age)
		: m_id{ id }, m_name{ name }, m_salary{salary}, m_age{age}
	{}

	virtual void show();

	virtual void input();

	string getName();

	int getSalary();

	int getAge();
};
