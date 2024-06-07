#include "BitcoinExchange.hpp"
#include "parse.hpp"

#include <fstream>
#include <ios>
#include <iostream>
#include <stdexcept>

static std::ifstream		open_infile(char const* path);
static DatabaseLine const&	find_closest_date(Date const&, Database const&);

Database
open_database(char const* path) {
	std::ifstream	infile = open_infile(path);

	return (parse::database(infile));
}

static std::ifstream
open_infile(char const* path) {
	std::ifstream	infile;
	infile.open(path);
	if (infile.is_open() == false)
		throw (std::ios_base::failure("Couldn't open file"));
	return (infile);
}

void
process_queries(char const* path, Database const& db) {
	std::ifstream	infile = open_infile(path);
	Query			query;

	parse::header(infile, "date | value");
	while (true) {
		try {
			if (!parse::getquery(infile, query))
				break;
			DatabaseLine const&	dbl = find_closest_date(query.date(), db);
			
			std::cout << query << " = " << (query.value() * dbl.rate()) << '\n';
		} catch (std::logic_error& e) {
			std::cerr << "Error: " << e.what() << std::endl;
		}
	}
	infile.close();
}

static DatabaseLine const&
find_closest_date(Date const& date, Database const& db) {
	if (db.begin()->date() > date)
		throw (std::logic_error("Cannot query earlier than first data entry."));

	Database::const_iterator	lower;

	for (Database::const_iterator it = db.begin(); it < db.end(); ++it) {
		if (it->date() == date)
			return (*it);
		else if (it->date() > date)
			return (*lower);
		lower = it;
	}
	return (*lower);
}
