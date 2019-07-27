/*
	@file: XMLComponent.hpp
	@author: Teran Bukenberger
	@date: 2019-07-27
	@description: Header for the XMLComponent
*/

#ifndef __XMLCOMPONENT__HPP
#define __XMLCOMPONENT__HPP

#include <string>
#include <list>

#include "..\IComposite.hpp"

class XMLComponent : public IComposite {
	std::string _key;
	std::list< IComposite > _children;

public:
	/* Constructor */
	XMLComponent( std::string key ) 
		: _key{ key } {}

	/* Methods */
	void AddChild( IComposite& child );
	std::string Print( int depth );
};

#endif // !__XMLCOMPONENT__HPP

