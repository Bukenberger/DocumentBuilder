/*
	@file: Director.cpp
	@author: Teran Bukenberger
	@date: 2019-07-27
	@description: Implementation for Director
*/

#include "Director.hpp"

#include <iostream>

// copy constructor
Director::Director( const Director& d ) {
	_console = d._console;
	_builder = d._builder;
}

/***** Getters *****/

void Director::BuildBranch() {
	UserConsole con;

	_builder->BuildBranch( con.GetBranch() );
}
void Director::BuildLeaf() {
	UserConsole con;
	std::pair< std::string, std::string > leaf = con.GetLeaf();
	
	_builder->BuildLeaf( leaf.first, leaf.second );
}

/***** Setters ******/

void Director::CloseBranch() {
	_builder->CloseBranch();
}

void Director::Print() {
	std::cout << "Director Class " <<_builder->GetDocument().Print( 0 );
}