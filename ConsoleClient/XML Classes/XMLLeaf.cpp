/*
	@file: XMLLeaf.cpp
	@author: Teran Bukenberger
	@date: 2019-07-27
	@description: XMLLeaf implementation
*/

#include "XMLLeaf.hpp"

std::string XMLLeaf::Print( int depth ) {
	// Calls the string constructor, creating a string of whitespaces, length based on depth * 4 ( to add 4 spaces for each layer )
	std::string space( depth * 4, ' ' );

	return space + "<" + _key + ">" + _value + "</" + _key + ">";
}