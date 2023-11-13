#ifndef QUERY_HPP
# define QUERY_HPP

# include <ctime>
# include <stdexcept>
# include <string>

class Query {
public:
	Query();
	~Query();
	Query(std::time_t, float);
	Query(Query const&);

	Query&	operator=(Query const&);

	std::time_t	date() const;
	float		value() const;

private:
	std::time_t	const	_date;
	float const			_value;
};

#endif // QUERY_HPP
