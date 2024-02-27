#include "Expression.hpp"

using FormException = Expression::FormException;

FormException::FormException():
	std::invalid_argument("Ill-formed RPN expression") {
}
