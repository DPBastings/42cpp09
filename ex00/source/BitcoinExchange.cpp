#include "BitcoinExchange.hpp"
#include "parse.hpp"

#include <fstream>
#include <ios>
#include <iostream>

static std::ifstream	open_infile(char const* path);

Queries
open_queries(char const* path) {
	std::ifstream	infile = open_infile(path);
	Queries			queries;

	queries = parse::queries(infile);
	infile.close();
	return (queries);
}

Database
open_database(char const* path) {
	std::ifstream	infile = open_infile(path);
	Database		db;

	db = parse::database(infile);
	infile.close();
	return (db);
}

static std::ifstream
open_infile(char const* path) {
	std::ifstream	infile;
	infile.open(path);
	if (infile.is_open() == false)
		throw (std::ios_base::failure("Couldn't open file."));
	return (infile);
}

void
process_queries(Queries const&, Database const&) {
	std::cout << "Aha." << std::endl;
}
