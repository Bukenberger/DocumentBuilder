/*
	@file: IDirector.hpp
	@author: Teran Bukenberger
	@date: 2019-07-27
	@description: Base class for the Director class. There is no implementation for this class.
*/

#ifndef __IDIRECTOR__HPP
#define __IDIRECTOR__HPP

class IDirector {
public:
	// virtual functions
	virtual void BuildBranch() = 0;
	virtual void BuildLeaf() = 0;
	virtual void CloseBranch() = 0;

	virtual ~IDirector() {}
};

#endif // !__IDIRECTOR__HPP