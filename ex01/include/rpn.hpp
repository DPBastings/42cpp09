#ifndef RPN_HPP
# define RPN_HPP

# include "Token.hpp"

# include <deque>
# include <istream>

class Expression: public std::deque<Token*> {
public:
	Expression();
	~Expression();
	Expression(Expression const&);
	
	Expression&	operator=(Expression const&);
}; // class Expression

bool	rpnexprget(std::istream&, Expression&);

#endif // RPN_HPP
