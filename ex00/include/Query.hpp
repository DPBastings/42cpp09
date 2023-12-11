#ifndef QUERY_HPP
# define QUERY_HPP

# include "Date.hpp"

# include <iostream>
# include <string>

class Query {
public:
	Query();
	~Query();
	Query(Date, float);
	Query(Query const&);

	Query&	operator=(Query const&);

	Date	date() const;
	float	value() const;

private:
	Date	_date;
	float	_value;
};

std::istream&	operator>>(std::istream&, Query&);
std::ostream&	operator<<(std::ostream&, Query const&);

#endif // QUERY_HPP
