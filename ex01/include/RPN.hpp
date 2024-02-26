#ifndef RPN_HPP
# define RPN_HPP

# include "Expression.hpp"

# include <istream>

void	read_rpn(std::istream&, Expression&);
void	read_rpn(char const*, Expression&);

#endif // RPN_HPP
