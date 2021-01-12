/*
	@file: Director.hpp
	@author: Teran Bukenberger
	@date: 2019-07-27
	@description: Director header
*/

#ifndef _DIRECTOR_HPP_
#define _DIRECTOR_HPP_

#include <string>

#include "AbstractBuilder.hpp"
#include "UserConsole.hpp"
#include "AbstractDirector.hpp"

class Director : public AbstractDirector {

	/***** Data Members *****/
	UserConsole _console;
	AbstractBuilder* _builder;

public:
	/***** Constructors *****/
	Director() = default;

	// one arg
	Director( AbstractBuilder* builder)
		: _builder{ builder } {}

	/***** Methods *****/
	void BuildBranch() override;
	void BuildLeaf() override;
	void CloseBranch() override;
	std::string Print();
};

#endif // !_DIRECTOR_HPP_