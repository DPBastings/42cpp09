#ifndef DATABASE_LINE_HPP
# define DATABASE_LINE_HPP

# include "Date.hpp"

# include <iostream>

class DatabaseLine {
public:
	DatabaseLine();
	~DatabaseLine();
	DatabaseLine(DatabaseLine const&);
	DatabaseLine(Date, float);
	
	DatabaseLine&	operator=(DatabaseLine const&);

	Date	date() const;
	float	rate() const;
private:
	Date	_date;
	float	_rate;
};

std::istream&	operator>>(std::istream&, DatabaseLine&);
std::ostream&	operator<<(std::ostream&, DatabaseLine const&);

#endif // DATABASE_LINE_HPP
