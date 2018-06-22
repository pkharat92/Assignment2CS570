/*
    Assignment 2 CS 570
    Guy Leonard
    Pierre Kharat
    Alfonso Herrera
*/
 
#include "a2.h"

using namespace std;

int main()
{
	displayMenu();
	return 0;
} // End int main()

void displayMenu() {
	
	int c;
	int i = 1;
	
	while(i == 1){
		
		cout << endl << endl;
		cout << "Multi-Processing File Editor Menu" << endl << endl;
		cout << "1. Create new directory files" << endl
			 << "2. Create new regular files" << endl
			 << "3. Read from a file" << endl
			 << "4. Write to a file" << endl
			 << "5. Print file status" << endl
			 << "6. Print directory listing" << endl
			 << "7. Exit" << endl << endl;
	
		cout << "Please select an option: ";
		
		cin >> c;
		
		cout << endl;
		
		if(c < 1 && c > 7){
			   
			cout << "Invalid argument, try again";
			continue;
		}
		
		switch (c) {
			case 1: createDirectory(); break;
			case 2: createNewRegularFiles(); break;
			case 3: readFromFile(); break;
			case 4: if(writeToFile() == 1){continue;}; break;
			case 5: printFileStatus(); break;
			case 6: printDirectoryListing(); break;
			case 7: return;
		} // End switch
		
		cout << "Type 1 for Menu or 0 for exit: ";
		
		cin >> i;
		
		cout << endl;
	}
	
	cout << "Have a nice day\n" << endl;
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
	
	cout << "\nFile: " << c << " created\n\n";
	
	outfile.close();
		
	return 0; 
} // End createRegularFiles()

int readFromFile() {
	
    string filename,str = "";
    char str_cp[256];

    cout << "Please enter filename: ";
    cin >> filename;

    const char * c = filename.c_str();

	pid_t PID = fork(); //create child process
	FILE *bFILE;
	
	if(PID == 0){ //Child proccess executes code here
	
		strcpy(str_cp,c);
		
		// Open file
	    ifstream infile;
	    infile.open(c);
	
	    // Fail check
	    if(infile.fail()) {
	    
			cout << "Cannot open file.\n";
			exit(1);
	    
	    } // End if
	    
	    cout << infile.rdbuf() << endl; //Print to the screen
	    infile.close();// Close file
	    
	    /*Check for the .bak file if exists erase the previous one*/
	    bool exists = (bFILE = fopen(strcat(str_cp,".bak"),"w")); 
	    
		if(exists){ //.bak file exists
		   
		    remove(str_cp);
		    fclose(bFILE); 
		    bFILE = fopen(str_cp,"w");
		}
		
		FILE * original = fopen(c,"r"); 
	    int ch;
	    
	    while((ch = getc(original)) != EOF)
			putc(ch,bFILE);
	    fclose(bFILE);
	    fclose(original);
	    /*End*/
	    
	    cout << endl;
		exit(0);
	}
	
	else if(PID > 0){ //Parent process executes code here
		wait(NULL);
	}
	
	else{	
		perror("fork() error");
		exit(-1);		
	}

    return 0;
}

int writeToFile() {
	int numBytes;
	char p;
	char str_cp[256];
	string filename;
	string str;
	FILE * pFile;
	vector <string> tokens;

	cout << endl << endl;
	cout << "Multi-Processing File Editor Menu" << endl << endl;
	cout << "1. Insert in File" << endl
		 << "2. Append to File" << endl
		 << "3. Overwrite File" << endl
		 << "4. Return to Previous Menu" << endl << endl;
	
	cout << "Please select an option: ";
	cin >> p;
	cout << endl;
	
	if(p == '4'){return 1;}
		
	cout << "Please enter filename: ";
	cin >> filename;
	const char * c = filename.c_str();
	strcpy(str_cp,c);
	
	
	pid_t PID, PID2, PID3; 
	PID= fork(); //create child process
	
	
	if(PID == 0){ //Child proccess executes code here
		switch (p) {
			case '1': pFile = fopen(c, "r+"); break;
			case '2': pFile = fopen(c, "a"); break;
			case '3': pFile = fopen(c, "w");  break;
		} // End switch
		
		
		
		/*Creating the backup file*/
		if(!fileExists(strcat(str_cp,".bak"))){ //file does not exist
			FILE *bFILE = fopen(str_cp,"w");
		    FILE * original = fopen(c,"r"); 
		    int ch;
		    
		    while((ch = getc(original)) != EOF)
				putc(ch,bFILE);
		    fclose(bFILE);
		    fclose(original);
		}
	    /*End*/
		
		if(pFile != NULL) {
			
			if(p == '1'){ //Specify which byte
				cout << "\nSpecify the amount of bytes: ";
				cin >> numBytes;
				cout << "\n\nWhat do you want to add or write to the file: " << endl;
				cin.ignore();
				getline(cin, str);
				const char * cstr = str.c_str();
				fseek (pFile, numBytes, SEEK_SET);
				fputs(cstr, pFile);
				fclose (pFile);
			}
			
			else{
				cout << "What do you want to add or write to the file: " << endl;
				cin.ignore();
				getline(cin, str);
				const char * cstr = str.c_str();
				fputs(cstr, pFile);
				fclose(pFile);
			}
		}//End if
		
		
		
		cout << endl;
		exit(0);
		
	}//End if
	
	else if(PID > 0){ //Parent process executes code here
		wait(NULL);
		/*PID2= fork();
		if(PID2 == 0){//Child
			// Open file
	    		ifstream infile;
	   		infile.open(c);
	
	    		// Fail check
	    		if(infile.fail()) {
				cout << "Cannot open file.\n";
				exit(1);
	    	    	} // End if
	    
			// Get content from file
			string line, intermediate;
	    		line = infile.rdbuf();
				
			// Tokenize the line
			stringstream check1(line);
			
			// Creates a new file to place the sorted contents into
			string filename2 = filename + "_sortAsc";
			const char * c2 = filename2.c_str();
			ofstream outfile(c2);
			
			// This is used to sort the tokens
			struct myclass {
  				bool operator() (int i,int j) { return (i<j);}
			} myobject;
			
			while(getline(check1, intermediate, ' ')) {
				tokens.pushback(intermediate);
			} // End while
			
			sort (tokens.begin(), tokens.end(), myobject);  
			
			// Writes the sorted contents to the new file
			for(int i = 0; i < tokens.size(); i++) {
				outfile << tokens[i] << '\n';
			} // End for
			
	   		infile.close();// Close file
			outfile.cose();
			exit(0);
		}
		else if(PID2 > 0){//Parent
			wait(NULL);
			PID3= fork();
			if(PID3 == 0){
				// Creates a new file to place the sorted contents into
				string filename3 = filename + "_sortDesc";
				const char * c3 = filename3.c_str();
				ofstream outfile(c3);
				
				// Writes the sorted contents to the new file
				reverse(tokens.begin(), tokens.end());
				for(int i = 0; i < tokens.size(); i++) {
					outfile << tokens[i] << '\n';
				} // End for
				
				outfile.close();
				exit(0);
			} // End if
			else if(PID3 > 0){
				
			} // End else if
		}*/ // End else if
	} // End else if
	
	else{
		perror("fork() error");
		exit(-1);		
	} // End if

	return 0;
} // End writeToFile()

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

/*
 * Check if a file exists already 
 */
bool fileExists(const char *fileName)
{
    std::ifstream infile(fileName);
    return infile.good();
}
