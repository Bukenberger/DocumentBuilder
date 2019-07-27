/*
	@file: JSONBuilder.cpp
	@author: Teran Bukenberger
	@date: 2019-07-27
	@description: JSONBuilder implementation
*/

#include "JSONBuilder.hpp"

void JSONBuilder::BuildBranch( std::string name ) {
	JSONComponent component( name );
	_depth++;

	_stack.top().AddChild( component );
	_stack.push( component );
}
void JSONBuilder::BuildLeaf( std::string name, std::string content ) {
	JSONLeaf leaf( name, content );
	_stack.top().AddChild( leaf );
}
void JSONBuilder::CloseBranch() {
	_depth--;
	if (_stack.size() > 1) {
		_stack.pop();
	}
}
IComposite JSONBuilder::GetDocument() {
	return _root;
}