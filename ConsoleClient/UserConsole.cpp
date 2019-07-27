#include "UserConsole.hpp"

/* Getters */
std::string& UserConsole::GetBranch() const { 
	return _branch; 
}

std::pair< std::string, std::string >& UserConsole::GetLeaf() const { 
	return _leaf; 
}

/* Setters */
void UserConsole::SetBranch( const std::vector< std::string >& props ) { 
	_branch = props[1];
}

void UserConsole::SetLeaf( const std::vector< std::string >& props ) { 
	_leaf = std::pair< std::string, std::string >( props[1], props[2] ); 
}