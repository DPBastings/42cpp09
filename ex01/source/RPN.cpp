#include "RPN.hpp"
#include "Token.hpp"

#include <stdexcept>
#include <sstream>

static aToken*	_char_to_token(char c);

void
read_rpn(char const* cstr, Expression& expr) {
	std::istringstream	iss(cstr);
	
	read_rpn(iss, expr);
}

void
read_rpn(std::istream& is, Expression& expr) {
	char	c;

	expr.empty();
	while (true) {
		is >> c;
		if (is.eof())
			break;
		expr.push_front(_char_to_token(c));
	}
	expr.reverse();
}

static aToken*	_char_to_token(char c) {
	switch (c) {
		case '+':
			return (new Addition);
		case '-':
			return (new Subtraction);
		case '*':
			return (new Multiplication);
		case '/':
			return (new Division);
		default:
			return (new Integer(c - '0'));
	}
}