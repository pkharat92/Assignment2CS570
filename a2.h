#include <iostream>
#include <sys/stat.h>
#include <sys/types.h>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <errno.h>

// Function prototypes
void displayMenu();
void createDirectory();
void createNewRegularFiles();
void createChildProcess();
void createChildProcessShadow();
void readFromFile();
void writeToFile();
void printFileStatus();
int printDirectoryListing();
