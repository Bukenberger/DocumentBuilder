/*
	@file: Director.hpp
	@author: Teran Bukenberger
	@date: 2019-07-27
	@description: Director header
*/

#ifndef __DIRECTOR__HPP
#define __DIRECTOR__HPP

#include "IBuilder.hpp"
#include "UserConsole.hpp"
#include "IDirector.hpp"

class Director : public IDirector {

	/***** Data Members *****/
	UserConsole _console;
	IBuilder _builder;

public:
	/***** Constructor *****/
	Director(IBuilder builder)
		: _builder{ builder } {}

	/***** Methods *****/
	void BuildBranch();
	void BuildLeaf();
	void CloseBranch();
	void Print();
};

#endif