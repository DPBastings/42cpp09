#ifndef EXPRESSION_HPP
# define EXPRESSION_HPP

# include "fwd.hpp"

# include <deque>
# include <iostream>

class Expression: public std::deque<aToken*> {
public:
	Expression() = default;
	~Expression();
	Expression(Expression const&);
	Expression(Expression&&);
	
	Expression&	operator=(Expression const&);
	Expression&	operator=(Expression&&);

	void	empty() noexcept;
	Integer	eval() const noexcept;
}; // class Expression

std::ostream&	operator<<(std::ostream&, Expression const&);

#endif // EXPRESSION_HPP
