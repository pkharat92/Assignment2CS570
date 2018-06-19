#include <iostream>

using namespace std;

// Function prototypes
void displayMenu();

int main()
{
	displayMenu();
	return 0;
} // End int main()

void displayMenu() {
	char c;

	cout << "Multi-Processing File Editor Menu" << endl << endl;
	cout << "1. Create new directory files" << endl
		<< "2. Create new regular files" << endl
		<< "3. Create child process to write sorted output" << endl
		<< "4. Create child process to shadow write/read regular files" << endl
		<< "5. Read from a file (print out to stdout)" << endl
		<< "6. Write to a file in either insert, append, or overwrite mode" << endl
		<< "7. Print file status (print out to stdout)" << endl
		<< "8. Print directory listing (contents of dir file) (print out to stdout)" << endl
		<< "9. Exit" << endl << endl;

	cout << "Please select an option: ";
	
	cin >> c;
	switch (c) {

	}
} // End void displayMenu()