/*
	@file: XMLComponent.cpp
	@author: Teran Bukenberger
	@date: 2019-07-27
	@description: XMLComponent implementation
*/

#include "XMLComponent.hpp"

void XMLComponent::AddChild( XMLComponent child ) {
	_children.push_back( child );
} // end AddChild()

/*
	Function: Print
	Purpose: Recursively prints XMLComponent objects and XMLLeaf objects
	Accepts: int
	Returns: std::string
*/
std::string XMLComponent::Print( int depth ) {

	// Calls the string constructor, creating a string of whitespaces, length based on depth * 4 ( to add 4 spaces for each layer )
	std::string space( depth * 4, ' ');
	
	std::string text = space + "<" + _key + ">\n";

	for (auto child : _children) {
		text += child.Print( depth + 1 ) + "\n";
	}

	text += space + "</" + _key + ">";

	return text;
} // end Print()