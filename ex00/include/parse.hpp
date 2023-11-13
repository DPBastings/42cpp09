#ifndef PARSE_HPP
# define PARSE_HPP

# include "BitcoinExchange.hpp"
# include "Query.hpp"

# include <istream>
# include <stdexcept>
# include <string>

namespace parse {
	char const*	query_delimiter = " | ";
	char const*	db_delimiter = ",";

	class ParseException: public std::invalid_argument {
	public:
		ParseException();
		~ParseException();
		ParseException(std::string const&);
	};

	Queries			query_file(std::istream&);
	Query			query_line(std::string const&);
	Database		database_file(std::istream&);
	DatabaseLine	database_line(std::string const&);
};

#endif // PARSE_HPP
