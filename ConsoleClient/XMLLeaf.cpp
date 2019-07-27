#include "XMLLeaf.hpp"
#include <string>

std::string XMLLeaf::Print( int depth ) {
	// multiplies the \t (tab) character by the depth passed in the parameter
	std::string space = "    ";

	//std::string tabs = String.Concat( Enumerable.Repeat( space, depth ) );

	//return $"{tabs}<{_key}>{_value}</{_key}>";
	return "<" + _key + ">" + _value + "</" + _key + ">";
}