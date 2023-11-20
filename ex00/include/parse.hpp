#ifndef PARSE_HPP
# define PARSE_HPP

# include "BitcoinExchange.hpp"
# include "Query.hpp"

# include <ctime>
# include <istream>
# include <stdexcept>
# include <string>

namespace parse {
	constexpr char	query_delimiter[] = " | ";
	constexpr char	database_delimiter[] = ",";

	class ParseException: public std::invalid_argument {
	public:
		ParseException();
		~ParseException();
		ParseException(std::string const&);

		ParseException&	operator=(ParseException const&);
	};

	Queries			query_file(std::ifstream&);
	Query			query_line(std::string const&);
	Database		database_file(std::ifstream&);
	DatabaseLine	database_line(std::string const&);
};

//std::istream&	operator>>(std::istream&, std::time_t);

#endif // PARSE_HPP
