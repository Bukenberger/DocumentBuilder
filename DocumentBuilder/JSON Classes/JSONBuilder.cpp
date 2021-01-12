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
	JSONComponent* component = new JSONComponent( name );
	++_depth;

	_stack.top()->AddChild( component );
	_stack.push( component );
}
void JSONBuilder::BuildLeaf( std::string name, std::string content ) {
	JSONLeaf* leaf = new JSONLeaf( name, content );
	_stack.top()->AddChild( leaf );
}
void JSONBuilder::CloseBranch() {
	--_depth;
	if (_stack.size() > 1) {
		_stack.pop();
	}
}
AbstractComposite* JSONBuilder::GetDocument() {
	return _root;
}