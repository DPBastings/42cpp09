#include "Token.hpp"

Addition::operator std::string() const {
	return ("+");
}

Subtraction::operator std::string() const {
	return ("-");
}

Multiplication::operator std::string() const {
	return ("*");
}

Division::operator std::string() const {
	return ("/");
}

Integer
Addition::operate(Integer const& left, Integer const& right) const noexcept {
	return (Integer(left.value() + right.value()));
}

Integer
Subtraction::operate(Integer const& left, Integer const& right) const noexcept {
	return (Integer(left.value() - right.value()));
}

Integer
Multiplication::operate(Integer const& left, Integer const& right) const noexcept {
	return (Integer(left.value() * right.value()));
}

Integer
Division::operate(Integer const& left, Integer const& right) const noexcept {
	return (Integer(left.value() / right.value()));
}
