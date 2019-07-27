/*
	@file: XMLBuilder.cpp
	@author: Teran Bukenberger
	@date: 2019-07-27
	@description: XMLBuilder implementation
*/

#include "XMLBuilder.hpp"

#include <string>

XMLBuilder::XMLBuilder()
	: _root{ XMLComponent( "root" ) } {
	_stack.push( _root );
}

void XMLBuilder::BuildBranch( std::string name ) {
	XMLComponent component( name );
	_depth++;

	_stack.top().AddChild( component );
	_stack.push( component );
}
void XMLBuilder::BuildLeaf( std::string name, std::string content ) {
	XMLLeaf leaf( name, content );
	_stack.top().AddChild( leaf );
}
void XMLBuilder::CloseBranch() {
	_depth--;
	if (_stack.size() > 1) {
		_stack.pop();
	}
}
IComposite XMLBuilder::GetDocument() {
	return _root;
}