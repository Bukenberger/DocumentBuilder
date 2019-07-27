#ifndef __XMLLEAF__HPP
#define __XMLLEAF__HPP

#include "IComposite.hpp"

#include <string>

class XMLLeaf : public IComposite {
	std:: string _key;
	std::string _value;

public:
	// constructor
	XMLLeaf( std::string key, std::string value )
		: _key{ key }, _value{ value } {}

	std::string Print( int depth );

	void AddChild( IComposite child ) {} // not used for the leaf, since leaves do not have children
};

#endif // !__XMLLEAF__HPP
