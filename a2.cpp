/* 
 * 
 * 
 */
 
#include "a2.h"

using namespace std;

int main()
{
	displayMenu();
	return 0;
} // End int main()

void displayMenu() {
	
	char c;
	int i = 1;
	
	while(i == 1){

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
		
		cout << endl;
		
		switch (c) {
			case '1': createDirectory(); break;
			case '2': createNewRegularFiles(); break;
			case '3': createChildProcess(); break;
			case '4': createChildProcessShadow(); break;
			case '5': readFromFile(); break;
			case '6': writeToFile(); break;
			case '7': printFileStatus(); break;
			case '8': printDirectoryListing(); break;
			case '9': return;
		} // End switch
		
		
		cout << "Type 1 for Menu or 0 for exit: ";
		
		cin >> i;
	}
	
	cout << endl << "Have a nice day" << endl;
} // End void displayMenu()

void createDirectory() {
	
	std::string pathName;
	
	cout << "Please type the name of the directory: ";
	
	cin >> pathName;
	
	if(mkdir(pathName.c_str(),S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH) == -1)//creating a directory
	{
		cerr << "Error: "<< strerror(errno) << endl;
		exit(1);
	}	
	
	cout << endl;
}

void createNewRegularFiles() {
	

}

void createChildProcess() {}

void createChildProcessShadow() {}

void readFromFile() {}

void writeToFile() {}

int printFileStatus() {
  struct stat FileAttrib;
  string filename;

  cout << "\nPlease enter the filename: ";
  cin >> filename;

  const char * c = filename.c_str();
 
  if(c == NULL)
  {
    printf("Argument missing!\n");
    exit(10);
  }

  if (stat(c, &FileAttrib) < 0)
    printf("\nFile Error Message = %s\n", strerror(errno));
  else {
    printf("\nI-node number: %ld\n", (long) FileAttrib.st_ino);
    printf("Mode: %lo (octal)\n", (unsigned long) FileAttrib.st_mode);
    printf("Link count: %ld\n", (long) FileAttrib.st_nlink);
    printf("Ownership: UID=%ld   GID=%ld\n", 
      (long) FileAttrib.st_uid, (long) FileAttrib.st_gid);
    printf("Preferred I/O block size: %ld bytes\n",
      (long) FileAttrib.st_blksize);
    printf("File size: %lld bytes\n",
      (long long) FileAttrib.st_size);
    printf("Blocks allocated: %lld\n",
      (long long) FileAttrib.st_blocks);
    printf("Last status change: %s", ctime(&FileAttrib.st_ctime));
    printf("Last file access: %s", ctime(&FileAttrib.st_atime));
    printf("Last file modification: %s", ctime(&FileAttrib.st_mtime));
  }
  
  return 0;
}

int printDirectoryListing() {
	DIR *dir;
	struct dirent *ent;
	
	if ((dir = opendir (".")) != NULL) {
		cout << "\n";
		// Print all files and directories within directory
		while ((ent = readdir (dir)) != NULL) {
			printf ("%s\n", ent->d_name);
		} // End while
		closedir (dir);
	}
	else {
		// Could not open directory
		perror("");
		return EXIT_FAILURE;
	} // End if
	
	cout << endl;
	
} // End printDirectoryListing()

void DisplayAgain(){}
