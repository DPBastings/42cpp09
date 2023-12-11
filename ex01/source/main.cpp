#include "rpn.hpp"

static bool	argcheck(int);

int
main(int argc, char** argv) {
	if (argcheck(argc) == false)
		return (1);

	
	std::cout << parse_rpn(argv[1]);
}

static bool
argcheck(int argc) {
	if (argc != 2) {
		std::cerr << "Usage: ./RPN [expression]" << std::endl;
		return (false);
	}
	return (true);
}
