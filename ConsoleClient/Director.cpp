#include "Director.hpp"

#include <iostream>

/***** Getters *****/

void Director::BuildBranch() {
	UserConsole con;

	_builder.BuildBranch( con.GetBranch() );
}
void Director::BuildLeaf() {
	UserConsole con;
	std::pair< std::string, std::string > leaf = con.GetLeaf();
	
	_builder.BuildLeaf( leaf.first, leaf.second );
}

/***** Setters ******/
void Director::CloseBranch() {
	_builder.CloseBranch();
}

void Director::Print() {
	std::cout << _builder.GetDocument().Print( 0 );
}