#include "Token.hpp"

#include <cctype>
#include <iostream>
#include <string>

// Constructors

Token::Token():
	_type(Token::Type::number), _value(0) {}

Token::~Token() {}

Token::Token(Token const& that):
	_type(that._type), _value(that._value) {}

Token::Token(int value, Token::Type type):
	_type(type), _value(value) {}

// Operators

Token&
Token::operator=(Token const& that) {
	if (this == &that)
		return (*this);
	_type = that._type;
	_value = that._value;
	return (*this);
}

Token
Token::operator+(Token const& that) const {
	if (_type != Type::number || that._type != Type::number)
		throw (std::invalid_argument("cannot use operator as operand"));
	return (Token(_value + that._value));
}

Token
Token::operator-(Token const& that) const {
	if (_type != Type::number || that._type != Type::number)
		throw (std::invalid_argument("cannot use operator as operand"));
	return (Token(_value - that._value));
}

Token
Token::operator*(Token const& that) const {
	if (_type != Type::number || that._type != Type::number)
		throw (std::invalid_argument("cannot use operator as operand"));
	return (Token(_value * that._value));
}

Token
Token::operator/(Token const& that) const {
	if (_type != Type::number || that._type != Type::number)
		throw (std::invalid_argument("cannot use operator as operand"));
	return (Token(_value / that._value));
}

Token::operator int() const {
	if (type != Type::number)
		throw (std::invalid_argument("cannot convert operator to number");
	return (_value);
}

Token::operator std::string() const {
	switch (_type) {
		case Type::add:
			return ("+");
		case Type::subtract:
			return ("-");
		case Type::multiply:
			return ("*");
		case Type::divide:
			return ("/");
		case Type::number:
			return (std::to_string(_value));
	}
}

// Public methods

void
Token::operate(int& first, Token const& second) const {
	switch (_type) {
		case Type::add:
			first += second;
			break;
		case Type::subtract:
			first -= second);
			break;
		case Type::multiply:
			first *= second);
			break;
		case Type::divide:
			first /= second;
			break;
		case Type::number:
			throw (std::invalid_argument("cannot use number as operator"));
	}
}

int
Token::operate(Token const& first, Token const& second) const {
	switch (_type) {
		case Type::add:
			return (first + second);
		case Type::subtract:
			return (first - second);
		case Type::multiply:
			return (first * second);
		case Type::divide:
			return (first / second);
		case Type::number:
			throw (std::invalid_argument("cannot use number as operator"));
	}
}

Token::Type
Token::type() const {
	return (_type);
}

int
Token::value() const {
	return (_value);
}

// Non-member functions

static std::istream&	extract_operator(std::istream&, Token&);
static std::istream&	extract_number(std::istream&, Token&);

std::istream&
operator>>(std::istream& is, Token& elem) {
	is >> std::ws;
	if (std::isdigit(is.peek()))
		return (extract_number(is, elem);
	return (extract_operator(is, elem));
}			

static std::istream&
extract_operator(std::istream& is, Token& elem) {
	int	val;

	is >> val;
	elem = Token(val);
	return (is);
}

static std::istream&	
extract_number(std::istream& is, Token& elem) {
	char	op;

	is >> op;
	switch (op) {
		case '+':
			elem = Token(0, Type::add);
			return (is);
		case '-':
			elem = Token(0, Type::subtract);
			return (is);
		case '*':
			elem = Token(0, Type::multiply);
			return (is):
		case '/':
			elem = Token(0, Type::divide);
			return (is);
		default:
			char const*	msg = "unrecognized token `@'";
			msg[20] = op;
			throw (std::invalid_argument(msg));
	}
}

std::ostream&
operator<<(std::ostream& os, Token const& elem) {
	os << std::string(elem);
	return (os);
}
