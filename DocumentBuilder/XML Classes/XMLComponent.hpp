/*
	@file: XMLComponent.hpp
	@author: Teran Bukenberger
	@date: 2019-07-27
	@description: Header for the XMLComponent
*/

#ifndef _XML_COMPONENT_HPP_
#define _XML_COMPONENT_HPP_

#include <string>
#include <vector>

#include "..\AbstractComposite.hpp"

class XMLComponent : public AbstractComposite {
	std::string _key;
	std::vector<AbstractComposite*> _children;

public:
	/* Constructor */
	XMLComponent( std::string key ) 
		: _key{ key } {}

	/* Methods */
	void AddChild( AbstractComposite* child );
	std::string Print( int depth );
};

#endif // !_XML_COMPONENT_HPP_

