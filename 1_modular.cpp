#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <Windows.h>
#include <stdio.h>

#include "module.h"

using namespace std;

struct Book {
	string book_name;
	string authors_name;
	unsigned int year_published;
	unsigned int page_count;
	unsigned int price;
};

int main() {
	fstream file;

	int books_written = 0;
	cout << "Initial file len: ";
	cin >> books_written;

	while (true) {
		cout << "\n\nmenu\n";
		cout << "1 - input\n";
		cout << "2 - output\n";
		cout << "3 - search\n";
		cout << "4 - exit\n";
		cout << "-------------\n";		

		cout << "choice: ";
		int choice{ inputFailCheck() };

		switch (choice) {
		case 1:
			system("cls");
			addRow(file, books_written);
			break;
		case 2:
			system("cls");
			printFile(file, books_written);
			break;
		case 3:
			system("cls");
			search(file, books_written);
			break;
		case 4:
			if (file.is_open())
				file.close();
			return 0;
		default:
			cout << "no such option, please try again";
		}
	}

}