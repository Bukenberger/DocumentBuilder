/*
	@file: XMLBuilder.cpp
	@author: Teran Bukenberger
	@date: 2019-07-27
	@description: XMLBuilder implementation
*/

#include "XMLBuilder.hpp"

void XMLBuilder::BuildBranch( std::string name ) {
	XMLComponent* component = new XMLComponent( name );
	++_depth;

	_stack.top()->AddChild( component );
	_stack.push( component );
}

void XMLBuilder::BuildLeaf( std::string name, std::string content ) {
	XMLLeaf* leaf = new XMLLeaf( name, content );
	_stack.top()->AddChild( leaf );
}

void XMLBuilder::CloseBranch() {
	--_depth;
	if (_stack.size() > 1) {
		_stack.pop();
	}
}

AbstractComposite* XMLBuilder::GetDocument() {
	return _root;
}