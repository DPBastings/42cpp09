#include "Token.hpp"

#include <stdexcept>

// Constructors

Integer::Integer(char valuec):
	_value(valuec - '0') {
	if (_value < 0 || _value > 9)
		throw (std::invalid_argument("Invalid character"));
}

Integer::Integer(int value):
	_value(value) {
}

// Operators

Integer::operator int() const noexcept {
	return (_value);
}

Integer::operator std::string() const {
	return (std::to_string(_value));
}

// Public methods

int
Integer::value() const noexcept {
	return (_value);
}

int&
Integer::value() noexcept {
	return (_value);
}
