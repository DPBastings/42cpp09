#include "Expression.hpp"
#include "Token.hpp"

using Stack = std::deque<Integer>;

static Integer	_process_integer(aToken*);
static Integer	_process_operator(Stack&, Operator*);
static void		_get_operands(Stack&, Integer&, Integer&);

Integer
Expression::eval() {
	Stack	stack;

	while (size() > 0) {
		if (dynamic_cast<Integer*>(front()))
			stack.push_front(_process_integer(take_front()));
		else
			stack.push_front(_process_operator(stack, static_cast<Operator*>(take_front())));
	}
	if (stack.size() != 1)
		throw (FormException());
	return (stack.front());
}

// Helpers

static Integer
_process_integer(aToken* tptr) {
	Integer*	iptr = dynamic_cast<Integer*>(tptr);
	Integer		x(*iptr);

	delete tptr;
	return (x);
}

static Integer
_process_operator(Stack& stack, Operator* op) {
	Integer	a;
	Integer	b;
	Integer	result;

	try {
		_get_operands(stack, a, b);
		if (dynamic_cast<Division*>(op) && b == 0) {
			delete op;
			throw (std::invalid_argument("cannot divide by zero"));
		}
		result = op->operate(a, b);
	} catch (Expression::FormException& e) {
		delete op;
		throw (e);
	}
	delete op;
	return (result);
}

static void
_get_operands(Stack& stack, Integer& a, Integer& b) {
	if (stack.size() < 2)
		throw (Expression::FormException());
	b = stack.front();
	stack.pop_front();
	a = stack.front();
	stack.pop_front();
}
