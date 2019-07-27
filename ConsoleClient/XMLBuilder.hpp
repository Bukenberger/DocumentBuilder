/*
	@file: XMLBuilder.hpp
	@author: Teran Bukenberger
	@date: 2019-07-27
	@description: Header for the XMLBuilder
*/

#ifndef __XMLBUILDER__HPP
#define __XMLBUILDER__HPP

#include "IBuilder.hpp"
#include "XMLComponent.hpp"
#include "XMLLeaf.hpp"

#include <string>
#include <stack>

class XMLBuilder : public IBuilder {
	int _depth = 0;
	std::stack<IComposite> _stack;
	IComposite _root;

public:
	XMLBuilder()
		: _root{ XMLComponent( "root" ) } {
		_stack.push( _root );
	}

	void BuildBranch( std::string name ) {
		XMLComponent component( name );
		_depth++;

		_stack.top().AddChild( component );
		_stack.push( component );
	}
	void BuildLeaf( std::string name, std::string content ) {
		XMLLeaf leaf( name, content );
		_stack.top().AddChild( leaf );
	}
	void CloseBranch() {
		_depth--;
		if (_stack.size() > 1) {
			_stack.pop();
		}
	}
	IComposite GetDocument() {
		return _root;
	}
};

#endif // !__XMLBUILDER__HPP