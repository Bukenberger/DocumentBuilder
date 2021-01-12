/*
	@file: JSONLeaf.cpp
	@author: Teran Bukenberger
	@date: 2019-07-27
	@description: JSONLeaf implementation
*/

#include "JSONLeaf.hpp"

std::string JSONLeaf::Print( int depth ) {
	// Calls the string constructor, creating a string of whitespaces, length based on depth * 4 ( to add 4 spaces for each layer )
	std::string space( depth * 4, ' ' );

	/*
		format:
				"key" : "value"
	*/
	return space + "\"" + _key + "\" : " + "\"" + _value + "\"";
}