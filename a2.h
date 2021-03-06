#include <iostream>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <errno.h>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <bits/stdc++.h>

// Function prototypes
void displayMenu();
void createDirectory();
int createNewRegularFiles();
int readFromFile();
int writeToFile();
int printFileStatus();
int printDirectoryListing();
int insertInFile();
int appendToFile();
int overwriteToFile();
