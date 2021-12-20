#pragma once

#include "Employee.h"

class Programmer : public Employee
{
private:
	string m_programmingLanguage;

public:

	Programmer() {}

	Programmer(int id, string name, int salary, int age)
		: Employee{ id, name, salary, age }
	{}

	virtual void show();
	virtual void input();
};