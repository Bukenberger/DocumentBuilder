/*
	@file: XMLBuilder.hpp
	@author: Teran Bukenberger
	@date: 2019-07-27
	@description: Header for the XMLBuilder
*/

#ifndef __XMLBUILDER__HPP
#define __XMLBUILDER__HPP

#include <string>
#include <stack>

#include "IBuilder.hpp"
#include "XMLComponent.hpp"
#include "XMLLeaf.hpp"

class XMLBuilder : public IBuilder {
	int _depth = 0;
	std::stack<IComposite> _stack;
	IComposite _root;

public:
	XMLBuilder()
		: _root{ XMLComponent( "root" ) } {
		_stack.push( _root );
	}

	void BuildBranch( std::string name );
	void BuildLeaf( std::string name, std::string content );
	void CloseBranch();
	IComposite GetDocument();
};

#endif // !__XMLBUILDER__HPP