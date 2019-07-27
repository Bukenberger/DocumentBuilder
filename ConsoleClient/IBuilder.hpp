/*
	@file: IBuilder.hpp
	@author: Teran Bukenberger
	@date: 2019-07-27
	@description: Base class header for other Builder classes (XMLBuilder, JSONBuilder). This class has no implementation.
*/

#ifndef __IBUILDER__HPP
#define __IBUILDER__HPP

#include "IComposite.hpp"

#include <string>

class IBuilder {
public:
	virtual void BuildBranch( std::string name ) {}
	virtual void BuildLeaf( std::string name, std::string content ) {}
	virtual void CloseBranch() {}
	virtual IComposite GetDocument() {};
};

#endif // !__IBUILDER_HPP