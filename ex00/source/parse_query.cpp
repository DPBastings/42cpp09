#include "parse.hpp"

#include "Query.hpp"

#include <ctime>
#include <fstream>
#include <sstream>
#include <string>

static std::istringstream&	operator>>(std::istringstream&, std::time_t);

Queries
parse::query(std::ifstream& infile) {
	Queries			queries;
	std::string		str;
	
	std::getline(infile, str);
	if (str != "date | value")
		throw (ParseException("Bad header."));
	while (std::getline(infile, str)) {
		if (infile.eof() == true)
			return (queries);
		Query	line = query_line(str);
		queries.push_back(line);
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
	if (delim != query_delimiter)
		throw (ParseException("Bad input => " + line));
	return (Query(date, value));
}

#include <iostream>

static std::istringstream&
operator>>(std::istringstream& iss, std::time_t& time) {
	std::tm	tm;

	iss >> std::get_time(&tm, "%Y-%m-%d");
	std::cout << iss.str() << std::endl;
	time = mktime(tm);
	return (iss);
}
