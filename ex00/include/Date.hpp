#ifndef DATE_HPP
# define DATE_HPP

#include <ctime>
#include <iostream>
#include <string>

class Date {
public:
	Date();
	~Date();
	Date(Date const&);
	Date(std::time_t);
	Date(std::string const&);

	Date&	operator=(Date const&);
	bool	operator==(Date const&) const;
	bool	operator<(Date const&) const;
	bool	operator>(Date const&) const;
	bool	operator<=(Date const&) const;
	bool	operator>=(Date const&) const;
			operator std::string() const;

	std::time_t	data() const;
private:
	std::time_t	_data;
}; // class Date

std::istream&	operator>>(std::istream&, Date&);
std::ostream&	operator<<(std::ostream&, Date const&);

#endif // DATE_HPP
