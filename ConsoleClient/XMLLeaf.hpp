/*
	@file: XMLLeaf.hpp
	@author: Teran Bukenberger
	@date: 2019-07-27
	@description: XMLLeaf header
*/

#ifndef __XMLLEAF__HPP
#define __XMLLEAF__HPP

#include <string>

#include "IComposite.hpp"

class XMLLeaf : public IComposite {
	std::string _key;
	std::string _value;

public:
	// constructor
	XMLLeaf( std::string key, std::string value )
		: _key{ key }, _value{ value } {}

	std::string Print( int depth );

	// void AddChild( IComposite child ) {} // not used for the leaf, since leaves do not have children
};

#endif // !__XMLLEAF__HPP
