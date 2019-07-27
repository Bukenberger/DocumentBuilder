/*
	@file: JSONLeaf.hpp
	@author: Teran Bukenberger
	@date: 2019-07-27
	@description: JSONLeaf header
*/

#ifndef __JSONLEAF__HPP
#define __JSONLEAF__HPP

#include <string>

#include "..\IComposite.hpp"

class JSONLeaf : public IComposite {
	std::string _key;
	std::string _value;

public:
	// constructor
	JSONLeaf( std::string key, std::string value )
		: _key{ key }, _value{ value } {}

	std::string Print( int depth );

	// void AddChild( IComposite child ) {} // not used for the leaf, since leaves do not have children
};

#endif // !__JSONLEAF__HPP
