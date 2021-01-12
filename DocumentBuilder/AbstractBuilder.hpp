/*
	@file: IBuilder.hpp
	@author: Teran Bukenberger
	@date: 2019-07-27
	@description: Base class header for other Builder classes (XMLBuilder, JSONBuilder). This class has no implementation.
*/

#ifndef _ABSTRACT_BUILDER_HPP_
#define _ABSTRACT_BUILDER_HPP_

#include <string>
#include <iostream>

#include "AbstractComposite.hpp"

class AbstractBuilder {
public:
	virtual void BuildBranch( std::string name ) = 0;
	virtual void BuildLeaf( std::string name, std::string content ) = 0;
	virtual void CloseBranch() = 0;
	virtual AbstractComposite* GetDocument() = 0;

	virtual ~AbstractBuilder() {};
};

#endif // !_ABSTRACT_BUILDER_HPP_