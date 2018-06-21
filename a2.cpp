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
		
		cout << endl << endl;
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
		
		//if(!isdigit(c)){
			
			//cout << "Invalid argument, try again" << endl;
			//continue;
		//}
		
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
		
		cout << endl;
	}
	
	cout << "Have a nice day" << endl;
} // End void displayMenu()

void createDirectory() {
	
	std::string pathName;
	
	cout << "Please type the name of the directory: ";
	cin >> pathName;
	
	if(mkdir(pathName.c_str(),S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH) == -1){ //creating a directory
		cerr << "Error: "<< strerror(errno) << endl;
		exit(1);
	}
	
	else 
		cout << endl <<"New directory " << pathName << " created.\n\n";	

}

int createNewRegularFiles() {
	
	string filename;
	string str;
	
	cout << "Please enter filename: ";
	cin >> filename;
	const char * c = filename.c_str();
	ofstream outfile(c);
	
	cout << "\nType what you want to write to file:\n\n";
	cin.ignore();
	getline(cin, str);
	cout << "\n";
	outfile << str << "\n";
	outfile.close();
		
	return 0; 
} // End createRegularFiles()

void createChildProcess() {
	
    string filename;

    cout << "Please enter filename: ";
    cin >> filename;
	
	
	
}

void createChildProcessShadow() {}

int readFromFile() {
    string filename;

    cout << "Please enter filename: ";
    cin >> filename;

    const char * c = filename.c_str();

    // Open file
    ifstream infile;
    infile.open(c);

    // Fail check
    if(infile.fail()) {
    
    cout << "Cannot open file.\n";
    exit(1);
    
    } // End if

    // Print file to console
    cout << infile.rdbuf() << endl;

    // Close file
    infile.close();
    cout << endl;

    return 0;
} // End readFromFile()

int writeToFile() {
  char c;

	cout << endl << endl;
	cout << "Multi-Processing File Editor Menu" << endl << endl;
	cout << "1. Insert in File" << endl
		<< "2. Append to File" << endl
		<< "3. Overwrite File" << endl
		<< "4. Return to Previous Menu" << endl << endl;
	
	cout << "Please select an option: ";
	cin >> c;
	cout << endl;
	
	switch (c) {
			case '1': insertInFile(); break;
			case '2': appendToFile(); break;
			case '3': overwriteFile(); break;
			case '4': displayMenu(); break;
		} // End switch

  return 0;
} // End writeToFile()

int insertInFile() {}

int appendToFile() {
	string filename;
	string str;

  cout << "Please enter filename: ";
  cin >> filename;
  const char * c = filename.c_str();
	ofstream outfile;
  outfile.open(c, ios_base::app);

	cout << "What do you want to add to the file: " << endl;
	cin.ignore();
	getline(cin, str);
	outfile << str;
	
	return 0;
} // End appendToFile()

int overwriteFile() {}

int printFileStatus() {
  
    struct stat FileAttrib;
    string filename;

    cout << "\nPlease enter the filename: ";
    cin >> filename;

	const char * c = filename.c_str();
	
	if(c == NULL){
	
	printf("Argument missing!\n");
	exit(10);
	} // End if
	
	if (stat(c, &FileAttrib) < 0)
	printf("\nFile Error Message = %s\n", strerror(errno));
	
	else {
	cout << "\n";
	
	switch (FileAttrib.st_mode & S_IFMT) {
	case S_IFBLK:  printf("block device\n");          break;
	case S_IFCHR:  printf("character device\n");      break;
	case S_IFDIR:  printf("directory\n");             break;
	case S_IFIFO:  printf("FIFO/pipe\n");             break;
	case S_IFLNK:  printf("symlink\n");               break;
	case S_IFREG:  printf("regular file\n");          break;
	case S_IFSOCK: printf("socket\n");                break;
	default:       printf("unknown?\n");              break;
	} // End switch
	
	printf("\nI-node number: %ld\n", (long) FileAttrib.st_ino);
	printf("Mode: %lo (octal)\n", (unsigned long) FileAttrib.st_mode);
	printf("Link count: %ld\n", (long) FileAttrib.st_nlink);
	printf("Ownership: UID=%ld   GID=%ld\n", 
	(long) FileAttrib.st_uid, (long) FileAttrib.st_gid);
	printf("Preferred I/O block size: %ld bytes\n",
	(long) FileAttrib.st_blksize);
	printf("File size: %lld bytes\n", (long long) FileAttrib.st_size);
	printf("Blocks allocated: %lld\n", (long long) FileAttrib.st_blocks);
	printf("Last status change: %s", ctime(&FileAttrib.st_ctime));
	printf("Last file access: %s", ctime(&FileAttrib.st_atime));
	printf("Last file modification: %s", ctime(&FileAttrib.st_mtime));
	
	cout << endl;
	} // End if
	
  return 0;
} // End printFileStatus()

int printDirectoryListing() {
	DIR *dir;
	struct dirent *ent;
	string filename;

  	cout << "Please specify the directory: ";
	cin >> filename;
 	const char * c = filename.c_str();
	cout << "\n";
	
	if ((dir = opendir (c)) != NULL) {
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
	return 0;
} // End printDirectoryListing()
