#include "parse.hpp"

#include <iostream>
#include <stdexcept>

static void	argcerr();

int
main(int argc, char const** argv) {
	if (argc != 2)
		return (argcerr(), 1);
	
	try {
		Database const	database = open_database();
		Queries const	queries = open_queries(argv[1]);
		
		process_queries(queries, database);
	} catch (std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return (1);
	}
	return (0);
}

static void	argcerr() {
	std::cerr << "Usage: ./btc <input_file>." << std::endl;
}
