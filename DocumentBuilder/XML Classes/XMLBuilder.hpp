/*
	@file: XMLBuilder.hpp
	@author: Teran Bukenberger
	@date: 2019-07-27
	@description: Header for the XMLBuilder
*/

#ifndef _XML_BUILDER_HPP_
#define _XML_BUILDER_HPP_

#include <string>
#include <stack>

#include "..\AbstractBuilder.hpp"
#include "XMLComponent.hpp"
#include "XMLLeaf.hpp"

class XMLBuilder : public AbstractBuilder {
	int _depth = 0;
	std::stack<AbstractComposite*> _stack;
	XMLComponent* _root;

public:
	XMLBuilder()
		: _root{ new XMLComponent( "root" ) } {
		_stack.push( _root );
	}

	void BuildBranch( std::string name ) override;
	void BuildLeaf( std::string name, std::string content ) override;
	void CloseBranch() override;
	AbstractComposite* GetDocument() override;
};

#endif // !_XML_BUILDER_HPP_