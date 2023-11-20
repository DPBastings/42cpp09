#include "parse.hpp"

#include <stdexcept>
#include <string>

using parse::ParseException;

ParseException::ParseException():
	std::invalid_argument("") {
}

ParseException::~ParseException() {
}

ParseException::ParseException(std::string const& msg):
	std::invalid_argument(msg) {
}

ParseException&
ParseException::operator=(ParseException const& that) {
	std::invalid_argument::operator=(that);
	return (*this);
}
