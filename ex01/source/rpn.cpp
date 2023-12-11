#include "rpn.hpp"

bool
rpnexprget(std::istream& is, Expression& expr) {
	Token	token;

	expr.clear();
	is >> token;
	expr.push_back(token);
	return (true);
}
