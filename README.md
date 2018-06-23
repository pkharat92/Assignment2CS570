Pierre Kharat: cssc1197
Alfonso Herrera: cssc1155

CS 570 Summer 2018, Assignment #2 Multi-Processing File Editor


README FILE


File Manifest

- README.txt: This is the current text file being read which will provide instructions
	      for the program.

- makefile:   This makefile is the one that will run and link our code creating an 
	      executable file.

- a2.h: Contains all the function prototypes and includes needed for the program to run.

-a2.cpp: This is the main file for the whole project. This will allow us to run the multi-
 processing file editor.

Compile Instructions

- We included, inside of the 'makefile', the 'gcc' command that will compile the 
  source code found inside the already mentioned 'makefile'.

Operating Instructions

- First, we need to execute the 'makefile' with the 'make' command. Then, after the
  executable is created, we need to run this executable and pass one argument. 
  
Design Decisions

- We created a menu with seven different options, allowing for the user to read from
 and write to a file, among other things.
 
 Work organization
 
 -Alfonso Herrera: Worked on the creation of the CreateDirectory function as well as 
 the readFromFile function and the writeToFile function in which the both of us worked.
 Also, I created the function that makes the ".bak" file in all of the specified cases.
 We both reviewed and edited the code from each other in order to obtain a better result.
 
 -Pierre Kharat:
