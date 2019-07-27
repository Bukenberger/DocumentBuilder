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
	IBuilder* _builder = nullptr;

public:
	/***** Constructors *****/
	Director() = default;

	// one arg
	Director(IBuilder* builder)
		: _builder{ builder } {}

	// copy constructor 
	Director( const Director& d );

	/***** Methods *****/
	void BuildBranch() override;
	void BuildLeaf() override;
	void CloseBranch() override;
	void Print();
};

#endif // !__DIRECTOR__HPP