#pragma once

#include "Employee.h"

class Tester : public Employee
{
private:
	string m_category;

public:
	Tester();

	Tester(int id, string name, int salary, int age);

	void input() override;

	void show() override;
};