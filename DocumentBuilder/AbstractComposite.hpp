/*
	@file: IComposite.hpp
	@author: Teran Bukenberger
	@date: 2019-07-27
	@description: Base class for other Component classes ( XMLComponent, JSONComponent )
*/

#ifndef _ABSTRACT_COMPOSITE_HPP_
#define _ABSTRACT_COMPOSITE_HPP_

#include <string>
#include <iostream>

class AbstractComposite {
public:
	// virtual functions
	virtual void AddChild( AbstractComposite* composite ) = 0;
	virtual std::string Print( int depth ) = 0;

	virtual ~AbstractComposite() {};
};

#endif // !_ABSTRACT_COMPOSITE_HPP_