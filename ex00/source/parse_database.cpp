#include "parse.hpp"

#include <ctime>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

static void	get_segments(std::string[2], std::string const&);

Database
parse::database_file(std::ifstream& infile) {
	Database	database;
	std::string	line;
	
	std::getline(infile, line);
	if (line != "date,exchange_rate")
		throw (ParseException("Bad header."));
	while (std::getline(infile, line)) {
		if (infile.eof() == true)
			return (database);
		DatabaseLine	entry = database_line(line);
		database.push_back(entry);
	}
	return (database);
}

DatabaseLine
parse::database_line(std::string const& line) {
	std::string	segments[2];
	get_segments(segments, line);
	return (DatabaseLine(Date(segments[0]), stof(segments[1])));
}

static void
get_segments(std::string segments[2], std::string const& line) {
	std::istringstream	iss(line);
	for (size_t i = 0; i < 2; i++) {
		if (!std::getline(iss, segments[i], '|'))
			throw (parse::ParseException("Bad database => " + line));
	}
}
