/*
	@file: JSONLeaf.hpp
	@author: Teran Bukenberger
	@date: 2019-07-27
	@description: JSONLeaf header
*/

#ifndef _JSON_LEAF_HPP_
#define _JSON_LEAF_HPP_

#include <string>

#include "..\AbstractComposite.hpp"

class JSONLeaf : public AbstractComposite {
	std::string _key;
	std::string _value;

public:
	// constructor
	JSONLeaf( std::string key, std::string value )
		: _key{ key }, _value{ value } {}

	std::string Print( int depth );

	 void AddChild( AbstractComposite* child ) {} // not used for the leaf, since leaves do not have children
};

#endif // !_JSON_LEAF_HPP_
