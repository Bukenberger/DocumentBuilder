/*
	@file: JSONBuilder.cpp
	@author: Teran Bukenberger
	@date: 2019-07-27
	@description: JSONBuilder implementation
*/

#include "JSONBuilder.hpp"

#include <typeinfo>
#include <iostream>

void JSONBuilder::BuildBranch( std::string name ) {
	// STUB CODE
	std::cout << "\nJSONBuilder Class" << std::endl;

	JSONComponent component( name );
	_depth++;

	_stack.top().AddChild( component );
	_stack.push( component );
}
void JSONBuilder::BuildLeaf( std::string name, std::string content ) {
	// STUB CODE
	std::cout << "\nJSONBuilder Class" << std::endl;

	JSONLeaf leaf( name, content );
	_stack.top().AddChild( leaf );
}
void JSONBuilder::CloseBranch() {
	// STUB CODE
	std::cout << "\nJSONBuilder Class" << std::endl;

	_depth--;
	if (_stack.size() > 1) {
		_stack.pop();
	}
}
IComposite JSONBuilder::GetDocument() {
	// STUB CODE
	std::cout << "\nJSONBuilder Class: Document - " << _root.to_string() << std::endl;
	
	return _root;
}