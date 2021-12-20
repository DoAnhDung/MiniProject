#include "CEO.h"

CEO::CEO()
	:Employee{}
{
}

void CEO::show()
{
	Employee::show();
	cout << " I am CEO of MegaLodon Company." << endl;
}

void CEO::input()
{
	Employee::input();
	cout << " Enter Stock" << endl;
	cin >> m_fund;
	
}
