/*
	@file: JSONComponent.cpp
	@author: Teran Bukenberger
	@date: 2019-07-27
	@description: JSONComponent implementation
*/

#include "JSONComponent.hpp"

void JSONComponent::AddChild( JSONComponent child ) {
	_children.push_back( child );
} // end AddChild()

/*
	Function: Print
	Purpose: Recursively prints JSONComponent objects and JSONLeaf objects
	Accepts: int
	Returns: std::string
*/
std::string JSONComponent::Print( int depth ) {

	// Calls the string constructor, creating a string of whitespaces, length based on depth * 4 ( to add 4 spaces for each layer )
	std::string space( depth * 4, ' ' );

	/* format:
				"key" :
				{
	*/
	std::string text = space + "\"" + _key + "\" :\n" + space + "\n";

	for (auto child : _children) {
		text += child.Print( depth + 1 ) + "\n";
	}

	text += space + '}';

	return text;
} // end Print()