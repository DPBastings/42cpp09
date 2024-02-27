#ifndef EXPRESSION_HPP
# define EXPRESSION_HPP

# include "fwd.hpp"

# include <deque>
# include <iostream>
# include <stdexcept>

class Expression: public std::deque<aToken*> {
public:
	class FormException;

	Expression() = default;
	~Expression();
	Expression(Expression const&);
	Expression(Expression&&);
	
	Expression&	operator=(Expression const&);
	Expression&	operator=(Expression&&);

	void	empty() noexcept;
	Integer	eval();

	aToken*	take_back() noexcept;
	aToken*	take_front() noexcept;

private:
	void	_eval_recur(Integer&);
}; // class Expression

std::ostream&	operator<<(std::ostream&, Expression const&);

class Expression::FormException: public std::invalid_argument {
public:
	FormException();
	~FormException() = default;
	FormException(FormException const&) = default;
	
	FormException&	operator=(FormException const&) = default;
}; // class Expression::FormException

#endif // EXPRESSION_HPP
