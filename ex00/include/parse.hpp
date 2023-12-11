#ifndef PARSE_HPP
# define PARSE_HPP

# include "BitcoinExchange.hpp"
# include "Query.hpp"

# include <ctime>
# include <istream>
# include <stdexcept>
# include <string>

namespace parse {
	class ParseException: public std::invalid_argument {
	public:
		ParseException();
		~ParseException();
		ParseException(std::string const&);

		ParseException&	operator=(ParseException const&);
	};

	Database	database(std::ifstream&);
	bool		getquery(std::ifstream&, Query&);
	void		header(std::ifstream&, char const*);
};

//std::istream&	operator>>(std::istream&, std::time_t);

#endif // PARSE_HPP
