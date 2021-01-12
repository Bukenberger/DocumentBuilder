/*
	@file: Director.cpp
	@author: Teran Bukenberger
	@date: 2019-07-27
	@description: Implementation for Director
*/

#include "Director.hpp"

#include <iostream>

void Director::BuildBranch() {
	_builder->BuildBranch( _console.GetBranch() );
}
void Director::BuildLeaf() {
	std::pair<std::string, std::string> leaf = _console.GetLeaf();
	_builder->BuildLeaf( leaf.first, leaf.second );
}

void Director::CloseBranch() {
	_builder->CloseBranch();
}

std::string Director::Print() {
	std::cout << _builder->GetDocument()->Print( 0 ) << std::endl;
	return _builder->GetDocument()->Print( 0 );
}