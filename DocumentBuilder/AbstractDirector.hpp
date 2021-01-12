/*
	@file: IDirector.hpp
	@author: Teran Bukenberger
	@date: 2019-07-27
	@description: Base class for the Director class. There is no implementation for this class.
*/

#ifndef _ABSTRACT_DIRECTOR_HPP_
#define _ABSTRACT_DIRECTOR_HPP_

class AbstractDirector {
public:
	// virtual functions
	virtual void BuildBranch() = 0;
	virtual void BuildLeaf() = 0;
	virtual void CloseBranch() = 0;

	virtual ~AbstractDirector() {};
};

#endif // !_ABSTRACT_DIRECTOR_HPP_