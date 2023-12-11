#include "parse.hpp"

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

Database
parse::database(std::ifstream& infile) {
	Database		database;
	DatabaseLine	entry;
	std::string		line;
	
	std::getline(infile, line);
	if (line != "date,exchange_rate")
		throw (ParseException("Bad header."));
	try {
		while (std::getline(infile, line)) {
			std::istringstream	iss(line);

			iss >> entry;
			database.push_back(entry);
		}
	} catch (ParseException& e) {
		std::string	msg("Bad input: " + line);
		std::string	thrownmsg(e.what());

		if (thrownmsg.length() == 0)
			msg += std::string("; ") + thrownmsg;
		throw (ParseException(msg));
	}
	return (database);
}

Queries
parse::queries(std::ifstream& infile) {
	Queries			queries;
	Query			query;
	std::string		line;
	
	std::getline(infile, line);
	if (line != "date | value")
		throw (ParseException("Bad header."));
	try {
		while (std::getline(infile, line)) {
			std::istringstream	iss(line);

			iss >> query;
			queries.push_back(query);
		}
	} catch (ParseException& e) {
		std::string	msg("Bad input: " + line);
		std::string	thrownmsg(e.what());

		if (thrownmsg.length() == 0)
			msg += std::string("; ") + thrownmsg;
		throw (ParseException(msg));
	}
	return (queries);	
}
