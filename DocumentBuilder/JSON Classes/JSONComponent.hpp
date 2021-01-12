/*
	@file: JSONComponent.hpp
	@author: Teran Bukenberger
	@date: 2019-07-27
	@description: Header for the JSONComponent
*/

#ifndef _JSON_COMPONENT_HPP_
#define _JSON_COMPONENT_HPP_

#include <string>
#include <vector>

#include "..\AbstractComposite.hpp"

class JSONComponent : public AbstractComposite {
	std::string _key;
	std::vector<AbstractComposite*> _children;

public:
	/* Constructor */
	JSONComponent( std::string key )
		: _key{ key } {}

	/* Methods */
	void AddChild( AbstractComposite* child ) override;
	std::string Print( int depth ) override;
	//std::string to_string() override { return "JSONComponent"; }
};

#endif // !_JSON_COMPONENT_HPP_

