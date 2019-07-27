/*
	@file: IComposite.hpp
	@author: Teran Bukenberger
	@date: 2019-07-27
	@description: Base class for other Component classes ( XMLComponent, JSONComponent )
*/

#ifndef __ICOMPOSITE__HPP
#define __ICOMPOSITE__HPP

#include <string>
#include <iostream>

class IComposite {
public:
	// virtual functions
	virtual void AddChild( IComposite& composite ) {}
	virtual std::string Print( int depth ) { return ""; }
	virtual std::string to_string() { return "IComposite"; }

	virtual ~IComposite() {}
};

#endif // !__ICOMPOSITE__HPP