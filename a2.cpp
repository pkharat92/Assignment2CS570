#include <iostream>
#include "a2.h"

using namespace std;

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
		case 1: createDirectory(); break;
		case 2: createNewRegularFiles(); break;
		case 3: createChildProcess(); break;
		case 4: createChildProcessShadow(); break;
		case 5: readFromFile(); break;
		case 6: writeToFile(); break;
		case 7: printFileStatus(); break;
		case 8: printDirectoryListing(); break;
		case 9: return;
	} // End switch
} // End void displayMenu()

void createDirectory() {}

void createNewRegularFiles() {}

void createChildProcess() {}

void createChildProcessShadow() {}

void readFromFile() {}

void writeToFile() {}

void printFileStatus() {}

void printDirectoryListing() {}
