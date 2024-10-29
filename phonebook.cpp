#include <iostream>
#include <fstream>
#include <string>
#include "file.h"

using namespace std;


struct phineBook {
	string name;
	int phone;
	
};


void beginContact(phineBook pb[], int& count) {
	ifstream file("contact.txt");
	if (!file) {
		cout << "error file\n";
		return;
	}
	else {
		while (file >> pb[count].name >> pb[count].phone) {
			//	cout << pb[count].name << ' ' << pb[count].phoned << endl;â
			count++;
		}
		file.close();
	}
}
void saveContacts(phineBook pb[], int count) {
    std::ofstream file("contact.txt");
    if (!file) {
        std::cout << "Error opening file to save contacts\n";
        return;
    }
    for (int i = 0; i < count; i++) {
        file << pb[i].name << " " << pb[i].phone << std::endl;
    }
    file.close();
}

void showContact(phineBook pb[], int count) {
		int i;
		for (i = 0; i < count; i++) {
			cout << pb[i].name << ' ' << pb[count].phone << endl;
		}

	}

void addContact(phineBook pb[], int& count) {

    cout << "Enter name: ";
    cin >> pb[count].name;
    cout << "Enter phone number: ";
    cin >> pb[count].phone;

    count++;

    saveContacts(pb, count);  

    cout << "Contact added successfully!\n";
}


void editContact(phineBook pb[], int count) {

    int index;

    cout << "Enter the number of the contact to edit: ";
    cin >> index;

    if (index > 0 && index <= count) {

        cout << "Enter new name: ";
        cin >> pb[index - 1].name;
        cout << "Enter new phone number: ";
        cin >> pb[index - 1].phone;

        saveContacts(pb, count);  

        cout << "Contact edited successfully!\n";
    }


    else {
        cout << "Invalid contact number.\n";
    }
}


void findContact(phineBook pb[], int count) {

    string searchName;
    int searchPhone;

    cout << "Enter name or phone number to search: ";
    cin.ignore();  

    if (cin.peek() >= '0' && cin.peek() <= '9') {
        cin >> searchPhone;

        for (int i = 0; i < count; i++) {
            if (pb[i].phone == searchPhone) {

                cout << "Contact found: " << pb[i].name << " " << pb[i].phone << endl;
                return;
            }
        }
    }
    else {
        getline(cin, searchName);
        for (int i = 0; i < count; i++) {
            if (pb[i].name == searchName) {
                cout << "Contact found: " << pb[i].name << " " << pb[i].phone << endl;
                return;
            }
        }
    }
    cout << "Contact not found.\n";
}


int phonebook() {
    cout << "\n\tPhone Book Menu\n\n";
    cout << " 1 = Show Contacts\n 2 = Add Contact\n 3 = Edit Contact\n 4 = Find a Contact\n 0 = Exit\n";

    short contact;
    int size = 0;
    phineBook pb[100]; 

  
    beginContact(pb, size);

    while (true) {
        cout << "\nEnter option: ";
        cin >> contact;
        switch (contact) {
        case 0:
            cout << "The program is stopped.\n";
            return 0;
        case 1:
            cout << "Saved contacts:\n";
            showContact(pb, size);
            break;
        case 2:
            addContact(pb, size);
            break;
        case 3:
            editContact(pb, size);
            break;
        case 4:
            findContact(pb, size);
            break;
        default:
            cout << "Invalid option. Try again.\n";
            break;
        }
    }



	cout << "\t\033[41m exid menu \1) exid \2)\n enter : \033[0m";

	short choice, res;
	cin >> choice;
	if (choice == 1) res = main();
	else if (choice == 2) exit;
	else cout << "error\n";

	return 0;
}