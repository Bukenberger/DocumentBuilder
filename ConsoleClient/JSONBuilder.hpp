/*
	@file: JSONBuilder.hpp
	@author: Teran Bukenberger
	@date: 2019-07-27
	@description: Header for the JSONBuilder
*/

#ifndef __JSONBUILDER__HPP
#define __JSONBUILDER__HPP

#include <string>
#include <stack>

#include "IBuilder.hpp"
#include "JSONComponent.hpp"
#include "JSONLeaf.hpp"

class JSONBuilder : public IBuilder {
	int _depth = 0;
	std::stack<IComposite> _stack;
	IComposite _root;

public:
	JSONBuilder()
		: _root{ JSONComponent( "root" ) } {
		_stack.push( _root );
	}

	void BuildBranch( std::string name );
	void BuildLeaf( std::string name, std::string content );
	void CloseBranch();
	IComposite GetDocument();
};

#endif // !__JSONBUILDER__HPP