#include "parse.hpp"

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

void
parse::header(std::ifstream& infile, char const* header) {
	std::string	line;

	std::getline(infile, line);
	if (line != header)
		throw (ParseException("Bad header."));
}

Database
parse::database(std::ifstream& infile) {
	Database		database;
	DatabaseLine	entry;
	std::string		line;
	
	parse::header(infile, "date,exchange_rate");
	try {
		while (std::getline(infile, line)) {
			std::istringstream	iss(line);

			iss >> entry;
			database.push_back(entry);
		}
	} catch (ParseException& e) {
		std::string	msg("Bad input: \"" + line + "\"");
		std::string	thrownmsg(e.what());

		if (thrownmsg.length() != 0)
			msg += std::string("; ") + thrownmsg;
		throw (ParseException(msg));
	}
	return (database);
}

bool
parse::getquery(std::ifstream& infile, Query& query) {
	std::string	line;
	
	try {
		if (!std::getline(infile, line))
			return (false);
		
		std::istringstream	iss(line);

		iss >> query;
	} catch (ParseException& e) {
		std::string	msg("Bad input: \"" + line + "\"");
		std::string	thrownmsg(e.what());

		if (thrownmsg.length() != 0)
			msg += std::string("; ") + thrownmsg;
		throw (ParseException(msg));
	}
	return (true);
}
