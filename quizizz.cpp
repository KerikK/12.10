#include <iostream>
#include <fstream>
#include <string>
#include "file.h"

using namespace std;

int quizizz() {

	cout << "\n\t\tQUIZIZZ\n\n";

	ifstream file("qui.txt");
	if (!file) {
		cout << "file not exist";
		return 1;
	}
	cout << "hh";
	short kol = 1, right =0;
	string line ;
	while (getline(file, line)) {
		cout << "Question #" << kol << endl;
		cout << line << endl;
		for (int i = 1; i <= 3; i++) {
			getline(file, line);
			cout << i << ")" << line << endl;
		}

		cout << "Enter variant";
		string user;
		cin >> user;

		
		file >> line;
		file.ignore();

		if (user == line) {
			cout << "\n true" << endl;
		}
		else {
			cout << "\nfolse" << endl;
	}

		kol++;
	}
	
	file.close();

	cout << "\n\t1) back menu\n2) exit\nYour choice: ";
		short  choice, res;
	cin >> choice;
	if (choice == 1) res = main();
	else if (choice == 2)exit;
	else cout << "selection error\n";
	return 0;
}