/*
Consider Telephone book database of N clients. Make use of hash table
implementation to quickly look up clients telephone number. Make use of
two collision handling techniques and compare them using number of
comparisons required to find a set of telephone numbers
unsigned long long = 64 bits


*/

#include<iostream>
#include<cstring>

using namespace std;

class Telephone {
	unsigned long long key;
	int address;
	int num;
	unsigned long long mobile[10];
	string name[10];

public:
	Telephone() {
		for (int i = 0; i < 10; i++) {
			mobile[i] = 0;
		}

		for (int i = 0; i < 10; i++) {
			name[i] = "-";
		}

	}

	
	int hash_function(unsigned long long key) {
		return key % 10;
	}

	void hash_collision_linear_probing(unsigned long long mobile[], string name[], unsigned long long key) {
		int adr = hash_function(key);
		while (mobile[(adr % 10)] != 0) {
			adr++;
		}
		//this function will stop once it finds the space and then we will assign address to the given key
		mobile[adr % 10] = key;
		cout << "Enter name of the person :- ";
		cin >> name[adr % 10];
		cout << endl;
	}

	void hash_collision_quadratic_probing(unsigned long long mobile[], string name[], unsigned long long key) {
		int adr = hash_function(key);
		int i = 1;
		while (mobile[(adr % 10)] != 0) {
			adr += (i * i);
			i++;
		}
		//this function will stop once it finds the space and then we will assign address to the given key
		mobile[adr % 10] = key;
		cout << "Enter name of the person :- ";
		cin >> name[adr % 10];
		cout << endl;
	}

	void insert_record() {

		cout << "Enter no of records you want to enter :- ";
		cin >> num;
		cout << endl;
		cout << "Which Collision handling technique do you want to use" << endl << "1. Linear Probing" << endl << "2. Quadratic Probing" << endl;
		int flag;
		cout << "Enter your Choice :- ";
		cin >> flag;
		cout << endl;

		while (num--) {
			cout << "Enter Telephone no :- ";
			cin >> key;
			cout << endl;

			address = hash_function(key);

			if (mobile[address] == 0) {
				mobile[address] = key;
				cout << "Enter name of the person :- ";
				cin >> name[address];
				cout << endl;
			}
			else if (flag == 1) {
				hash_collision_linear_probing(mobile, name, key);
			}

			else if (flag == 2) {
				hash_collision_quadratic_probing(mobile, name, key);
			}

		}
	}

	void display() {
		cout << "Index\tName\tMobile" << endl;
		for (int i = 0; i < 10; i++) {
			cout << i << "\t" << name[i] << "\t" << mobile[i] << endl;
		}
	}


};

int main() {

	Telephone t1;
	int choice;
	char ch;

	do {
		cout << "*Telephone Directory*" << endl;
		cout << "1. Insert record in Directory" << endl;
		cout << "2. Display Telephone Directory" << endl;
		cout << "3. Exit" << endl;
		cout << endl << "Enter your choice :- ";
		cin >> choice;
		cout << endl;

		switch (choice) {

		case 1:
			t1.insert_record();
			break;
		case 2:
			t1.display();
			break;
		}
	} while (choice < 3);

	return 0;
}