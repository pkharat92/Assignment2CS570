#include <iostream>
#include <sys/stat.h>
#include <sys/types.h>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <errno.h>
#include <vector>

// Function prototypes
void displayMenu();
void createDirectory();
int createNewRegularFiles();
void createChildProcess();
void createChildProcessShadow();
int readFromFile();
void writeToFile();
int printFileStatus();
int printDirectoryListing();
int insertInFile() {};
int appendToFile() {};
int overwriteToFile() {};
