/*
	@file: main.cpp
	@author: Teran Bukenberger
	@date: 2019-07-27
	@description: launches the application
*/

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS // to use strtok instead of strtok_s

// C System libraries
#include <stdio.h>
#include <string.h>

// C++ System Libraries
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <fstream>

// Headers
#include "AbstractBuilder.hpp"
#include "UserConsole.hpp"
#include "Director.hpp"
#include "JSON Classes\JSONBuilder.hpp"
#include "XML Classes\XMLBuilder.hpp"

// Function declaration headers
void Usage();
void InvalidInput();
void ModeNotSet();
void WriteToFile( std::string fileName, std::string fileExtension );
std::vector<std::string> split( std::string str, std::string sep );

int main() {
	std::cout << "Document Builder Console Client - Teran Bukenberger\n";

	UserConsole console;
	Director d;

	// save content when printed
	std::string fileContent;
	std::string fileExtension;

	bool isSet = false;

	Usage();

	do {
		std::cout << "> ";
		// read input into command string
		std::string command;
		std::getline( std::cin, command );

		// convert all characters in command string to lowercase
		std::for_each( command.begin(), command.end(), []( char& c ) {
			c = tolower( c );
		} );
		
		std::vector<std::string> _commands = split( command, ":" );

		if (_commands.size() == 1) {
			if (_commands[0] == "help") {
				Usage();
			}
			else if (_commands[0] == "exit") {
				return EXIT_SUCCESS;
			}
			else if (_commands[0] == "close") {
				if (isSet) {
					d.CloseBranch();
				}
				else {
					ModeNotSet();
				}
			}
			else if (_commands[0] == "print") {
				if (isSet) {
					d.Print();
				}
				else {
					ModeNotSet();
				}
			}
			else if (_commands[0] == "export") {
				if ( fileExtension.empty() ) {
					std::cout << "No content to write." << std::endl;
				}
				else {
					fileContent = d.Print();
					WriteToFile(fileContent, fileExtension);
				}
			}
			else {
				InvalidInput();
			}
		}
		else if (_commands.size() == 2) {
			if (_commands[0] == "mode") {
				if (_commands[1] == "json") {
					fileExtension = ".json";
					d = Director( new JSONBuilder );
					isSet = true;
				}
				else if (_commands[1] == "xml") {
					fileExtension = ".xml";
					d = Director( new XMLBuilder );
					isSet = true;
				}
				else {
					InvalidInput();
				}
			}
			else if (_commands[0] == "branch") {
				if (isSet) {
					console.SetBranch( _commands );
					d.BuildBranch();
				}
				else {
					ModeNotSet();
				}
			}
			else {
				InvalidInput();
			}
		}
		else if (_commands.size() == 3) {
			if (_commands[0] == "leaf") {
				if (isSet) {
					console.SetLeaf( _commands );
					d.BuildLeaf();
				}
				else {
					ModeNotSet();
				}
			}
			else {
				InvalidInput();
			}
		}
		else {
			InvalidInput();
		}
	} while (true);

	return 0;
} // end main()

void Usage() {
	std::cout << "Usage:\n";

	std::vector< std::string > options = {
							"help",
							"mode:<JSON|XML>",
							"branch:<name>",
							"leaf:<name>:<content>",
							"close",
							"print",
							"exit",
							"export"
	};

	std::vector< std::string > descriptions = {
								"-Prints Usage (this page).",
								"-Sets mode to JSON or XML. Must be set before creating or closing.",
								"-Creates a new branch, assigning it the passed name.",
								"-Creates a new leaf, assigning the passed name and content.",
								"-Closes the current branch, as long as it is not the root.",
								"-Prints the doc in its current state to the console.",
								"-Exits the application.",
								"-Exports the written document to a file"
	};

	for (unsigned index = 0; index < options.size(); ++index) {
		// length of the longest option (leaf:<name>:<content>) - the current option
		int length = options[3].size() - options[index].size() + 2;

		std::string space( length, ' ' );

		// print repeating spaces after each option based on the length of the longest option
		std::cout << "    " + options[ index ] + space + descriptions[ index ] + "\n";
	}
	std::cout << "\n";
} // end Usage()

void WriteToFile( std::string fileContent, std::string fileExtension ) {
	std::cout << "Enter a file name (without extension): ";
	std::string fileName;

	for (;;) {
		std::cin >> fileName;
		if (!fileName.empty())
			break;
		else
			std::cout << "\nPlease enter a value: " << std::endl;
	}

	std::cout << "Writing to file...\n" << std::endl;
	std::ofstream file( fileName + fileExtension );
	file << fileContent;
	file.close();
	std::cout << "Complete." << std::endl;
}

void InvalidInput() {
	std::cout << "Invalid input. For Usage, type 'Help'\n";
} // end InvalidInput()

void ModeNotSet() {
	std::cout << "Error. Mode has not been set. For usage, type 'Help'\n";
} // end ModeNotSet()

std::vector< std::string > split( std::string str, std::string sep ) {

	char* cstr = const_cast< char* >( str.c_str() );
	char* current;
	std::vector<std::string> arr;
	current = strtok( cstr, sep.c_str() );

	while (current != nullptr) {
		arr.push_back( current );
		current = strtok( nullptr, sep.c_str() );
	}

	return arr;
} // end split()

#endif // !_CRT_SECURE_NO_WARNINGS