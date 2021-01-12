/*
	@file: JSONBuilder.hpp
	@author: Teran Bukenberger
	@date: 2019-07-27
	@description: Header for the JSONBuilder
*/

#ifndef _JSON_BUILDER_HPP_
#define _JSON_BUILDER_HPP_

#include <string>
#include <stack>

#include "..\AbstractBuilder.hpp"
#include "JSONComponent.hpp"
#include "JSONLeaf.hpp"

class JSONBuilder : public AbstractBuilder {
	int _depth = 1;
	std::stack<AbstractComposite*> _stack;
	JSONComponent* _root;

public:
	JSONBuilder()
		: _root { new JSONComponent( "root" ) } {
		_stack.push( _root );
	}

	void BuildBranch( std::string name ) override;
	void BuildLeaf( std::string name, std::string content ) override;
	void CloseBranch() override;
	AbstractComposite* GetDocument() override;

};

#endif // !_JSON_BUILDER_HPP_