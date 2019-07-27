/*
	@file: XMLBuilder.cpp
	@author: Teran Bukenberger
	@date: 2019-07-27
	@description: XMLBuilder implementation
*/

#include "XMLBuilder.hpp"

void XMLBuilder::BuildBranch( std::string name ) {
	// STUB CODE
	std::cout << "\nXMLBuilder Class" << std::endl;

	XMLComponent component( name );
	_depth++;

	_stack.top().AddChild( component );
	_stack.push( component );
}
void XMLBuilder::BuildLeaf( std::string name, std::string content ) {
	// STUB CODE
	std::cout << "\nXMLBuilder Class" << std::endl;

	XMLLeaf leaf( name, content );
	_stack.top().AddChild( leaf );
}
void XMLBuilder::CloseBranch() {
	// STUB CODE
	std::cout << "\nXMLBuilder Class" << std::endl;

	_depth--;
	if (_stack.size() > 1) {
		_stack.pop();
	}
}
IComposite XMLBuilder::GetDocument() {
	// STUB CODE
	std::cout << "\nXMLBuilder Class" << std::endl;
	return _root;
}