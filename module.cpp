#include "module.h"

struct Book {
	string book_name;
	string authors_name;
	unsigned int year_published;
	unsigned int page_count;
	unsigned int price;
};

int inputFailCheck()
{
	int input;
	while (true) {
		cin >> input;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "\nInput error, try again: ";
		}
		else {
			cin.ignore(32767, '\n');
			return input;
		}
	}
};
Book t[10];

void printFile(fstream& file, int& books_written) {
	system("cls");
	

	file.open("kek.dat", ios::in | ios::binary);
	file.read((char*)&t, sizeof(t));
	file.close();

	cout << "Record # | authors_name | book_name | year_published | page_count | price \n";
	for (size_t idx = 0; idx < books_written; idx++) {
		cout << "Record # " << idx << " | " << t[idx].authors_name << " | " << t[idx].book_name << " | " << t[idx].year_published << " | " << t[idx].page_count << " | " << t[idx].price << " | " << endl;
	}
}

void addRow(fstream& file, int& books_written) {
	Book b_temp;

	system("cls");
	file.open("kek.dat", ios::out | ios::app | ios::binary);

	cout << "\nauthors_name: ";
	cin >> b_temp.authors_name;

	cout << "\nbook_name: ";
	cin >> b_temp.book_name;

	cout << "\nyear_published: ";
	cin >> b_temp.year_published;

	cout << "\npage_count: ";
	cin >> b_temp.page_count;

	cout << "\nprice: ";
	cin >> b_temp.price;

	file.write((char*)&b_temp, sizeof(b_temp));
	file.close();

	books_written += 1;
	return;
}

void search(fstream& file, int& books_written) {
	system("cls");

	// выбор поля для поиска
	string str_search_term;
	int int_search_term;
	int operand;
	cout << "specify search term (1-5): ";
	int search_choice;
	cin >> search_choice;
	while (search_choice > 5 || search_choice < 1) {
		cout << "\nBruh, (1-5): ";
		cin >> search_choice;
	}

	cout << "\nYou chose " << search_choice << ", which means - ";
	if (search_choice == 1)
		cout << "authors name\n";
	if (search_choice == 2)
		cout << "book name\n";
	if (search_choice == 3)
		cout << "year published\n";
	if (search_choice == 4)
		cout << "page count\n";
	if (search_choice == 5)
		cout << "price\n";

	// ввод "строки" для поиска
	cout << "what to search for?: ";
	if (search_choice == 1 || search_choice == 2) {
		cin >> str_search_term;
	}
	else {
		cin >> int_search_term;
		cout << "Enter operand (1 - >, 2 - <, 3 - =): ";
		cin >> operand;
		if (operand < 1 or operand > 3) {
			cout << "\nDon't have such operand\n";
		}
	};

	file.open("kek.dat", ios::in | ios::binary);
	file.read((char*)&t, sizeof(t));
	// поиск
	for (size_t i{ 0 }; i < books_written; ++i) {
		bool found = false;

		Book inf = t[i];

		switch (search_choice) {
		case 1:
			if (inf.authors_name.find(str_search_term) != string::npos) {
				found = true;
			}
			break;
		case 2:
			if (inf.book_name.find(str_search_term) != string::npos) {
				found = true;
			}
			break;
		case 3:
			if (operand == 3 && inf.year_published == int_search_term) {
				found = true;
			}
			if (operand == 1 && inf.year_published > int_search_term) {
				found = true;
			}
			if (operand == 2 && inf.year_published < int_search_term) {
				found = true;
			}
			break;
		case 4:
			if (operand == 3 && inf.page_count == int_search_term) {
				found = true;
			}
			if (operand == 1 && inf.page_count > int_search_term) {
				found = true;
			}
			if (operand == 2 && inf.page_count < int_search_term) {
				found = true;
			}
			break;
		case 5:
			if (operand == 3 && inf.price == int_search_term) {
				found = true;
			}
			if (operand == 1 && inf.price > int_search_term) {
				found = true;
			}
			if (operand == 2 && inf.price < int_search_term) {
				found = true;
			}
			break;
		}
		if (!found)
			continue;

		cout << "\nFound: " << " | " << inf.authors_name << " | " << inf.book_name << " | " << inf.year_published << " | " << inf.page_count << " | " << inf.price << " | " << endl;
	}
	file.close();
};