#include "RPN.hpp"
#include "Token.hpp"
#include "fwd.hpp"

#include <cstddef>
#include <iostream>

static bool	_argcheck(int, char**);

int
main(int argc, char** argv) {
	if (_argcheck(argc, argv) == false)
		return (EXIT_FAILURE);

	Expression	expr;

	read_rpn(argv[1], expr);
	// std::cout << expr << '\n';
	try {
		std::cout << expr.eval() << '\n';
	} catch (std::invalid_argument& e) {
		std::cerr << e.what() << '\n';
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static bool
_argcheck(int argc, char**) {
	if (argc != 2) {
		std::cerr << "Usage: ./RPN [expression]\n";
		return (false);
	}
	return (true);
}
