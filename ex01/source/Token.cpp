#include "Token.hpp"

// Non-member functions

std::ostream&
operator<<(std::ostream& os, aToken const& obj) {
	os << std::string(obj);
	return (os);
}