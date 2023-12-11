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
	Queries		queries(std::ifstream&);
};

//std::istream&	operator>>(std::istream&, std::time_t);

#endif // PARSE_HPP
