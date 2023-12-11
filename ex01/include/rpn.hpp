#ifndef RPN_HPP
# define RPN_HPP

# include "Token.hpp"

# include <deque>
# include <istream>

using Expression = std::deque<Token>;

bool	rpnexprget(std::istream&, Expression&);

#endif // RPN_HPP
