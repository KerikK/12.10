#include <iostream>
#include "quizizz.h"
#include "phonebook.h"

using namespace std;

int main() {

	system("chcp 1251>null");

	cout << "\033[34mfail\033[0m \n";
	cout  << "\n manu\n1) a quiz\n2) phone book\n Enter: ";
	short choice, res,ph;
	cin >> choice;
	switch (choice) {
	case 1:
		res = quizizz();
		break;

	case 2:
		res = phonebook();
		break;
	
	default: cout << "wrong choice!"; break;
	}

}