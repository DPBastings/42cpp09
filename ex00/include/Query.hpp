#ifndef QUERY_HPP
# define QUERY_HPP

# include "Date.hpp"

# include <stdexcept>
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
	Date const	_date;
	float const	_value;
};

#endif // QUERY_HPP
