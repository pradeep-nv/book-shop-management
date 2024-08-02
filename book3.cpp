// C++ program to illustrate bookshop
// management system using File Handling
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <fstream>
#include <string>
#include <limits>

using namespace std;

// Bookshop Class
class bookshope {
public:
	void control_panel();
	void add_book();
	void show_book();
	void check_book();
	void update_book();
	void del_book();
};

// Function to display the menus
void bookshope::control_panel()
{
	system("cls");
	cout << "\n\n\t\t\t\tCONTROL PANEL";
	cout << "\n\n1. ADD BOOK";
	cout << "\n2. DISPLAY BOOKS";
	cout << "\n3. CHECK PARTICULAR BOOK";
	cout << "\n4. UPDATE BOOK";
	cout << "\n5. DELETE BOOK";
	cout << "\n6. EXIT";
}

// Function to add book
void bookshope::add_book()
{
	system("cls");
	fstream file;
	fstream ffile;
	int no_copy, b_id, firstField;
	string b_name, a_name;
	cout << "\n\n\t\t\t\tADD BOOKS";
	ifstream inputFile;
    inputFile.open("book.txt",ios::out | ios::app);
    ifstream File;
	File.open("index.txt", ios::out | ios::app);

    if (inputFile.is_open()) {
    	bool bookIdExists;
    	do {
	    	do {
				std::cout << "\nEnter the bookId: ";
			    while(!(std::cin >> b_id)) {
				    std::cin.clear();
				    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				    std::cout << "\nInvalid input.\n\nEnter the bookId: ";
				}
		        std::string line;
		        bookIdExists = false;
		        while (std::getline(inputFile, line)) {
	            std::istringstream iss(line);
	            iss >> firstField;
		            
		            if (firstField == b_id) {
		                bookIdExists = true;
		                break;
		            }
		        }
		        
		        inputFile.close();
		
		        if (bookIdExists) {
		            std::cout << "\nbookId already present. Please retype the bookId.\n";
		        }
		    } while(bookIdExists);
		    if (b_id<1)
				cout << "Invalid input. Enter again\n";
		} while (b_id<1);
	} 
	cout << "\nBook Name : ";
	cin >> b_name;
	cout << "\nAuthor Name : ";
	cin >> a_name;
	do {
		cout << "\nNo. of Books : ";
		while (!(std::cin >> no_copy)) {
	        std::cin.clear();
	        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	        std::cout << "\nInvalid input\n\nNo. of Books : ";
	    }
	    if (no_copy<1)
			cout << "Invalid input. Enter again\n";
	} while (no_copy<1);

	// Open file in append or
	// output mode
	file.open("book.txt",
			ios::out | ios::app);
	file << b_id << " "
		<< b_name << " " << a_name
		<< " " << no_copy << "\n";
	ffile.open("index.txt", ios::out | ios::app);
	ffile<< b_id<<"\n";
	file.close();
}

// Function to display book
void bookshope::show_book()
{
	system("cls");
	fstream file;
	int no_copy;
	string b_name, b_id, a_name;
	cout << "\n\n\t\t\t\t\tAll BOOKS";

	// Open the file in input mode
	file.open("book.txt", ios::in);
	if (!file)
		cout << "\n\nFile Opening Error!";
	else {

		cout << "\n\n\nBook ID\t\tBook"
			<< "\t\tAuthor\t\tNo. of "
				"Books\n\n";
		file >> b_id >> b_name;
		file >> a_name >> no_copy;

		// Till end of file is reached
		while (!file.eof()) {

			cout << " " << b_id
				<< "\t\t" << b_name
				<< "\t\t" << a_name
				<< "\t\t" << no_copy
				<< "\n\n";
			file >> b_id >> b_name;
			file >> a_name >> no_copy;
		}

		system("pause");

		// Close the file
		file.close();
	}
}

// Function to check the book
void bookshope::check_book()
{
	system("cls");
	fstream file;
	int no_copy, count = 0;
	string b_id, b_name, a_name, b_idd;

	cout << "\n\n\t\t\t\tCheck "
		<< "Particular Book";

	// Open the file in input mode
	file.open("book.txt", ios::in);
	if (!file)
		cout << "\n\nFile Opening Error!";
	else {

		cout << "\n\nBook ID : ";
		cin >> b_idd;
		file >> b_id >> b_name;
		file >> a_name >> no_copy;

		while (!file.eof()) {

			if (b_idd == b_id) {

				system("cls");
				cout << "\n\n\t\t\t\t"
					<< "Check Particular Book";
				cout << "\n\nBook ID : "
					<< b_id;
				cout << "\nName : "
					<< b_name;
				cout << "\nAuthor : "
					<< a_name;
				cout << "\nNo. of Books : "
					<< no_copy;
				cout << endl
					<< endl;
				count++;
				break;
			}
			file >> b_id >> b_name;
			file >> a_name >> no_copy;
		}
		file.close();
		if (count == 0)
			cout << "\n\nBook ID Not Found\n";
			system("pause");
	}
}

// Function to update the book
void bookshope::update_book()
{
	system("cls");
	fstream file, file1;
	int no_copy, no_co, count = 0;
	string b_name, b_na, a_name;
	string a_na, b_idd, b_id;

	cout << "\n\n\t\t\t\tUpdate Book Record";
	file1.open("book1.txt",
			ios::app | ios::out);
	file.open("book.txt", ios::in);

	if (!file)
		cout << "\n\nFile Opening Error!";
	else {

		cout << "\n\nBook ID : ";
		cin >> b_id;
		file >> b_idd >> b_name;
		file >> a_name >> no_copy;

		// Till end of file is reached
		while (!file.eof()) {
			if (b_id == b_idd) {
				system("cls");
				cout << "\t\t\t\t"
					<< "Update Book Record";
				cout << "\n\nNew Book Name : ";
				cin >> b_na;
				cout << "\nAuthor Name : ";
				cin >> a_na;
				cout << "\nNo. of Books : ";
				cin >> no_co;
				file1 << " " << b_id << " "
					<< b_na << " "
					<< a_na << " " << no_co
					<< "\n\n";
				count++;
			}
			else
				file1 << " " << b_idd
					<< " " << b_name
					<< " " << a_name
					<< " " << no_copy
					<< "\n\n";
			file >> b_idd >> b_name;
			file >> a_name >> no_copy;
		}
		if (count == 0)
			cout << "\n\nBook ID"
				<< " Not Found...";
	}
	cout << endl;
	system("pause");

	// Close the files
	file.close();
	file1.close();
	remove("book.txt");
	rename("book1.txt",
		"book.txt");
}

// Function to delete book
void bookshope::del_book()
{
	system("cls");
	fstream file, file1, file2, file3;
	int no_copy, count = 0;
	string b_id, b_idd, b_name, a_name;
	cout << "\n\n\t\t\t\tDelete a Book";

	// Append file in output mode
	file1.open("book1.txt",
			ios::app | ios::out);
	file.open("book.txt",ios::in);
	file3.open("index1.txt",
			ios::app | ios::out);
	file2.open("index.txt",ios::in);
	if (!file)
		cout << "\n\nFile Opening Error...";
	else {

		cout << "\n\nBook ID : ";
		cin >> b_id;
		file >> b_idd >> b_name;
		file >> a_name >> no_copy;
		while (!file.eof()) {

			if (b_id == b_idd) {

				system("cls");
				cout << "\n\n\t\t\t\t"
					<< "Delete a Book";
				cout << "\n\nBook is Deleted "
						"Successfully...\n\n";
				count++;
			}
			else
				file1 << " " << b_idd
					<< " " << b_name
					<< " " << a_name
					<< " " << no_copy
					<< "\n\n";
			file >> b_idd >> b_name;
			file >> a_name >> no_copy;
		}
		file2 >> b_idd;
		while (!file2.eof()) {

			if (b_id == b_idd) {

				system("cls");
			}
			else
				file3 << " " << b_idd
					<< "\n\n";
				file2 >> b_idd;
		}
		if (count == 0)
			cout << "\n\nBook ID "
				<< "Not Found...\n";
	}
	system("pause");

	// Close the file
	file.close();
	file1.close();
	remove("book.txt");
	rename("book1.txt",
		"book.txt");
	file2.close();
	file3.close();
	remove("index.txt");
	rename("index1.txt", "index.txt");
}

// Function for book shop record
void bookShopRecord()
{
	int choice;
	char x;
	bookshope b;

	while (1) {

		b.control_panel();
		cout << "\n\nEnter your choice : ";
		cin >> choice;
		switch (choice) {

		case 1:
			do {

				b.add_book();
				cout << "\n\nWant to add"
					<< " another book? "
						"(y/n) : ";
				cin >> x;
			} while (x == 'y');
			break;

		case 2:
			b.show_book();
			break;

		case 3:
			b.check_book();
			break;
		case 4:
			b.update_book();
			break;

		case 5:
			b.del_book();
			break;

		case 6:
			exit(0);
			break;

		default:
			cout << "\n\nINVALID CHOICE\n";
		}
	}
}

// Driver Code
int main()
{
	// Function Call
	bookShopRecord();

	return 0;
}
