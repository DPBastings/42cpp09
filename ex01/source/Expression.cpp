#include "Expression.hpp"
#include "Token.hpp"

static void	push_as_base(Expression&, aToken const*);

// Constructors

Expression::~Expression() {
	empty();
}

Expression::Expression(Expression const& that) {
	for (aToken const* token: that)
		push_as_base(*this, token);
}

Expression::Expression(Expression&& that) {
	for (auto& token: that) {
		push_back(token);
		token = nullptr;
	}
}

// Operators

Expression&
Expression::operator=(Expression const& that) {
	if (this == &that)
		return (*this);
	empty();
	for (auto const& token: that)
		push_as_base(*this, token);
	return (*this);
}

Expression&
Expression::operator=(Expression&& that) {
	if (this == &that)
		return (*this);
	empty();
	for (auto& token: that) {
		push_back(token);
		token = nullptr;
	}
	return (*this);
}

// Public methods

void
Expression::empty() noexcept {
	for (auto& token: *this)
		if (dynamic_cast<Integer const*>(token))
			delete static_cast<Integer*>(token);
		else if (dynamic_cast<Addition const*>(token))
			delete static_cast<Addition*>(token);
		else if (dynamic_cast<Subtraction const*>(token))
			delete static_cast<Subtraction*>(token);
		else if (dynamic_cast<Multiplication const*>(token))
			delete static_cast<Multiplication*>(token);
		else if (dynamic_cast<Division const*>(token))
			delete static_cast<Division*>(token);
	clear();
}

Integer
Expression::eval() const noexcept {
	Integer	res = dynamic_cast<Integer const&>(*front());

	for (Expression::const_iterator it = begin() + 1; it < end(); it += 2) {
		res.calculate(dynamic_cast<Integer const&>(**it), *(it + 1));
	}
	return (res);
}

// Non-member functions

std::ostream&
operator<<(std::ostream& os, Expression const& obj) {
	for (auto const& item: obj)
		os << *item << ' ';
	return (os);
}

// Helpers
static void
push_as_base(Expression& expr, aToken const* token) {
	if (dynamic_cast<Integer const*>(token))
		expr.push_back(new Integer(*(static_cast<Integer const*>(token))));
	else if (dynamic_cast<Addition const*>(token))
		expr.push_back(new Addition(*(static_cast<Addition const*>(token))));
	else if (dynamic_cast<Subtraction const*>(token))
		expr.push_back(new Subtraction(*(static_cast<Subtraction const*>(token))));
	else if (dynamic_cast<Multiplication const*>(token))
		expr.push_back(new Multiplication(*(static_cast<Multiplication const*>(token))));
	else if (dynamic_cast<Division const*>(token))
		expr.push_back(new Division(*(static_cast<Division const*>(token))));
}
