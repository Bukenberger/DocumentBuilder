/*
	@file: XMLLeaf.hpp
	@author: Teran Bukenberger
	@date: 2019-07-27
	@description: XMLLeaf header
*/

#ifndef _XML_LEAF_HPP_
#define _XML_LEAF_HPP_

#include <string>

#include "..\AbstractComposite.hpp"

class XMLLeaf : public AbstractComposite {
	std::string _key;
	std::string _value;

public:
	// constructor
	XMLLeaf( std::string key, std::string value )
		: _key{ key }, _value{ value } {}

	std::string Print( int depth );

	 void AddChild( AbstractComposite* child ) {} // not used for the leaf, since leaves do not have children
};

#endif // !_XML_LEAF_HPP_
