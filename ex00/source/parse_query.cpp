#include "parse.hpp"

#include "Query.hpp"

#include <ctime>
#include <fstream>
#include <sstream>
#include <string>

Queries
parse::query_file(std::ifstream& infile) {
	Queries			queries;
	std::string		line;
	
	std::getline(infile, line);
	if (line != "date | value")
		throw (ParseException("Bad header."));
	while (std::getline(infile, line)) {
		if (infile.eof() == true)
			return (queries);
		Query	query = query_line(line);
		queries.push_back(query);
	}
	return (queries);	
}

Query
parse::query_line(std::string const& line) {
	std::istringstream	iss(line);
	std::time_t			date;
	std::string			delim;
	float				value;

	iss >> date >> delim >> value;
	if (value < 0)
		throw (ParseException("Not a positive number."));
	else if (value >= 1000)
		throw (ParseException("Too large a number."));
	if (delim != parse::query_delimiter)
		throw (ParseException("Bad input => " + line));
	return (Query(date, value));
}
