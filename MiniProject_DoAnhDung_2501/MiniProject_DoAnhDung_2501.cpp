#include <iostream>
#include <vector>
#include <fstream>
#include "Employee.h"
#include "Programmer.h"
#include "Tester.h"
#include "Manager.h"
#include "Utils.h"
#include "CEO.h"
#include <algorithm>



void showMenu() {
	cout << " |======================MENU========================|" << '\n';
	cout << " | 1. Add employee.                                 |" << '\n';
	cout << " | 2. Edit employee.                                |" << '\n';
	cout << " | 3. Remove employee.                              |" << '\n';
	cout << " | 4. Sort by name.                                 |" << '\n';
	cout << " | 5. Show all employees.                           |" << '\n';
	cout << " | 6. Sort by Salary.                               |" << '\n';
	cout << " | 7. Sort by Age.                                  |" << '\n';
	cout << " | 0. Exit.                                         |" << '\n';
	cout << " |==================================================|" << '\n';
	cout << " -------------------Please choose-------------------- ";
}

void showAddMenu() {
	cout << "|=======================MENU=======================|" << '\n';
	cout << "| 1. Add programmer.                               |" << '\n';
	cout << "| 2. Add tester.                                   |" << '\n';
	cout << "| 3. Add manager.                                  |" << '\n';
	cout << "| 4. Add CEO.                                      |" << '\n';
	cout << "|==================================================|" << '\n';
	cout << "--------------------Please choose------------------- ";
}

void showSortMenu() {
	cout << "|========MENU=========|" << endl;
	cout << "| 1.Increase.         |" << endl;
	cout << "| 2.Decrease.         |" << endl;
	cout << "|=====================|" << endl;
	cout << "|++++Please choose++++|";
}


void showAll(vector<Employee*> list) {
	for (auto e : list) {
		e->show();
	}
}

int main()
{
	
	vector<Employee*> list{};

	ifstream fileIn{ "input.txt" };

	string line;
	while (getline(fileIn, line)) {

		auto vec = Utils::split(line, ",");

		if (vec.at(0) == "1") {
			list.push_back(new Programmer{ stoi(vec.at(1)), vec.at(2), stoi(vec.at(3)), stoi(vec.at(4)) });
		}
		else if (vec.at(0) == "2") {
			list.push_back(new Tester{ stoi(vec.at(1)), vec.at(2), stoi(vec.at(3)), stoi(vec.at(4)) });
		}
		else if (vec.at(0) == "3") {
			list.push_back(new Manager{ stoi(vec.at(1)), vec.at(2), stoi(vec.at(3)), stoi(vec.at(4)) });
		}
		else if (vec.at(0) == "4") {
			list.push_back(new CEO{ stoi(vec.at(1)), vec.at(2), stoi(vec.at(3)), stoi(vec.at(4)) });
		}
		  
	}


	int choose;
	bool exit{ false };

	string name;

	showMenu();
	while (true) {

		cin >> choose;
		cin.ignore(100, '\n');

		switch (choose)
		{
		case 1:
		{
			cout << "Add employee" << '\n';

			int chooseType;
			showAddMenu();
			cin >> chooseType;
			cin.ignore(100, '\n');

			switch (chooseType) {
			case 1:
			{
				Employee* e{ new Programmer{} };
				e->input();
				list.push_back(e);
			}
			break;
			case 2:
			{
				Employee* e{ new Tester{} };
				e->input();
				list.push_back(e);
			}
			break;
			case 3:
			{
				Employee* e{ new Manager{} };
				e->input();
				list.push_back(e);

			}
			break;
			case 4:
			{
				Employee* e{ new CEO{} };
				e->input();
				list.push_back(e);
			}
			break;
			}
			break;

		}
		break;
		case 2:
		{
			cout << "Edit employee" << '\n';
			cout << "Enter name: ";
			getline(cin, name);

			for (auto e : list) {
				if (e->getName().compare(name) == 0) {
					e->input();
					break;
				}
			}
		}
		break;
		case 3:
		{
			cout << "Remove employee" << '\n';
			cout << "Enter name: ";
			getline(cin, name);
			

			for (auto e : list) {
				if (e->getName().compare(name) == 0) {
					auto index = std::find(list.begin(), list.end(), e);
					list.erase(index);
					break;
				}
			}
		}
		break;
		case 4:
			cout << "Sort by name" << '\n' << '\n';
			std::sort(
				list.begin(),
				list.end(),
				[](const auto& e1, const auto& e2) {return e1->getName() < e2->getName(); }
			);
			cout << "" << '\n';
			showAll(list);
			break;
		case 5:
			cout << "Show all employees" << '\n' << '\n';
			showAll(list);
			break;
		case 6:
			cout << "Sort by Salary" << '\n' << '\n';
			int chooseSort;
			showSortMenu();
			cin >> chooseSort;
			switch (chooseSort) {
			case 1:
				std::sort(
					list.begin(),
					list.end(),
					[](const auto& e1, const auto& e2) {return e1->getSalary() < e2->getSalary(); }
				);
				showAll(list);
				break;

			case 2:
				std::sort(
					list.begin(),
					list.end(),
					[](const auto& e1, const auto& e2) {return e1->getSalary() > e2->getSalary(); }
				);
				cout << "" << '\n';
				showAll(list);
				break;
			}
			break;
		case 7:
			cout << "Sort by Age" << '\n' << '\n';
			int chooseSortAge;
			showSortMenu();
			cin >> chooseSortAge;
			switch (chooseSortAge) {
			case 1:
				std::sort(
					list.begin(),
					list.end(),
					[](const auto& e1, const auto& e2) {return e1->getAge() < e2->getAge(); }
				);
				showAll(list);
				break;

			case 2:
				std::sort(
					list.begin(),
					list.end(),
					[](const auto& e1, const auto& e2) {return e1->getAge() > e2->getAge(); }
				);
				cout << "" << '\n';
				showAll(list);
				break;
			}
			break;
		case 0:
			cout << "Exit" << '\n';
			exit = true;
			break;
		}
		if (exit) {
			break;
		}
		cout << "" << '\n' << '\n';
		showMenu();
	}

}

