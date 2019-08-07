/*
	@file: UserConsole.cpp
	@author: Teran Bukenberger
	@date: 2019-07-27
	@description: Implementation for UserConsole
*/

#include "UserConsole.hpp"

#include <string>

/* Current issue - GetBranch method is not being called, it can be assumed it is the same for the other functions */

// static data members
std::string UserConsole::_branch;
std::pair< std::string, std::string > UserConsole::_leaf;

// copy assignment operator
UserConsole& UserConsole::operator=( const UserConsole& con ) {
	_branch = con._branch;
	_leaf = con._leaf;

	return *this;
}

/* Getters */
std::string UserConsole::GetBranch() const { 
	return _branch;
}

std::pair< std::string, std::string > UserConsole::GetLeaf() const { 
	return _leaf; 
}

/* Setters */
void UserConsole::SetBranch( const std::vector< std::string >& props ) { 
	_branch = props[1];
}

void UserConsole::SetLeaf( const std::vector< std::string >& props ) { 
	_leaf = std::pair< std::string, std::string >( props[1], props[2] ); 
}