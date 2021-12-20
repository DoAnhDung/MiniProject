#pragma once
#include"Employee.h"
class CEO:public Employee
{
private:
	int m_fund;
public:
	CEO();
	CEO(int id, string name, int salary, int age)
		:Employee{id, name, salary, age}
	{}

	virtual void show();
	virtual void input();
};

