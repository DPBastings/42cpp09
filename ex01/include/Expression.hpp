#ifndef EXPRESSION_HPP
# define EXPRESSION_HPP

# include "fwd.hpp"

# include <forward_list>
# include <iostream>
# include <stdexcept>

class Expression: public std::forward_list<aToken*> {
public:
	class FormException;

	Expression() = default;
	~Expression();
	Expression(Expression const&);
	Expression(Expression&&);
	
	Expression&	operator=(Expression const&);
	Expression&	operator=(Expression&&);

	size_t	size() const noexcept;

	void	empty() noexcept;
	Integer	eval();

	aToken*	take_back() noexcept;
	aToken*	take_front() noexcept;
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
