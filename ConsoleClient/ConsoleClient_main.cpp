/*
	@file: ConsoleClient_main.cpp
	@author: Teran Bukenberger
	@date: 2019-07-27
	@description: 
*/

#include <stdio.h>
#include <string.h>

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

#include "IBuilder.hpp"
#include "UserConsole.hpp"
#include "Director.hpp"
#include "JSONBuilder.hpp"
#include "XMLBuilder.hpp"

// function headers
void Usage();
void InvalidInput();
void ModeNotSet();

int main() {
	std::cout << "Document Builder Console Client - Teran Bukenberger\n";

	UserConsole console;

	Director* d = nullptr;

	bool isSet = false;

	Usage();

	do {
		// read input into command string
		std::string command;// = Console.ReadLine().ToLower();
		std::getline( std::cin, command );

		// convert all characters in command string to lowercase
		std::for_each( command.begin(), command.end(), []( char& c ) {
			c = ::tolower( c );
		} );
		
		std::cout << command;

		//char* pch;
		std::vector< std::string > _commands; // = command.Split( ":" );

		//pch = strtok( command, ":" );


		if (_commands.size() == 1) {
			if (_commands[0] == "help") {
				Usage();
			}
			else if (_commands[0] == "exit") {
				return EXIT_SUCCESS;
			}
			else if (_commands[0] == "close") {
				if (isSet) {
					d->CloseBranch();
				}
				else {
					ModeNotSet();
				}
			}
			else if (_commands[0] == "print") {
				if (isSet) {
					d->Print();
				}
				else {
					ModeNotSet();
				}
			}
			else {
				InvalidInput();
			}
		}
		else if (_commands.size() == 2) {
			if (_commands[0] == "mode") {
				if (_commands[1] == "json") {
					//d = new JSONBuilder;
					dynamic_cast< JSONBuilder* >( d );
					isSet = true;
				}
				else if (_commands[1] == "xml") {
					//d = new XMLBuilder;
					dynamic_cast< XMLBuilder* >( d );
					isSet = true;
				}
				else {
					InvalidInput();
				}
			}
			else if (_commands[0] == "branch") {
				if (isSet) {
					console.SetBranch( _commands );
					d->BuildBranch();
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
					d->BuildLeaf();
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
							"exit"
	};

	std::vector< std::string > descriptions = {
								"-Prints Usage (this page).",
								"-Sets mode to JSON or XML. Must be set before creating or closing.",
								"-Creates a new branch, assigning it the passed name.",
								"-Creates a new leaf, assigning the passed name and content.",
								"-Closes the current branch, as long as it is not the root.",
								"-Prints the doc in its current state to the console.",
								"-Exits the application."
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

void InvalidInput() {
	std::cout << "Invalid input. For Usage, type 'Help'";
} // end InvalidInput()

void ModeNotSet() {
	std::cout << "Error. Mode has not been set. For usage, type 'Help'";
} // end ModeNotSet()