/*
	@file: JSONComponent.hpp
	@author: Teran Bukenberger
	@date: 2019-07-27
	@description: Header for the JSONComponent
*/

#ifndef __JSONCOMPONENT__HPP
#define __JSONCOMPONENT__HPP

#include <string>
#include <list>

#include "..\IComposite.hpp"

class JSONComponent : public IComposite {
	std::string _key;
	std::list< IComposite > _children;

public:
	/* Constructor */
	JSONComponent( std::string key )
		: _key{ key } {}

	/* Methods */
	void AddChild( IComposite& child ) override;
	std::string Print( int depth ) override;
	std::string to_string() override { return "JSONComponent"; }
};

#endif // !__JSONCOMPONENT__HPP

