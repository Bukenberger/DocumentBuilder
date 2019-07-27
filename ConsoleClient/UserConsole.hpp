/*
	@file: UserConsole.hpp
	@author: Teran Bukenberger
	@date: 2019-07-27
	@description: Header for the UserConsole class.
				  
				  The purpose of this class is to store user input from the console.
*/

#ifndef __USERCONSOLE__HPP
#define __USERCONSOLE__HPP

#include <string>
#include <vector>

class UserConsole {
	/***** PRIVATE DATA MEMBERS ******/
	std::string _branch;
	std::pair< std::string, std::string > _leaf;

public:
	/***** CONSTRUCTORS *****/

	// copy assignment operator
	UserConsole& operator=( const UserConsole& );

	/***** GETTERS & SETTERS ******/

	std::string GetBranch() const;
	std::pair< std::string, std::string > GetLeaf() const;

	void SetBranch( const std::vector< std::string >& props );
	void SetLeaf( const std::vector< std::string >& props );

}; // end class

#endif // !__USERCONSOLE__HPP
