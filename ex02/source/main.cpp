#include "PMM.hpp"

#include <iostream>
#include <iterator>
#include <string>

static void	_parse_args(CtrA&, CtrB&, int, char**);
static void	_sort(CtrA&, CtrB&);
template<typename CTR>
static void	_ctr_print_line(CTR const& ctr, char const* header) {
	std::cout << header;
	ctr_print(ctr, std::cout);
	std::cout << '\n';
}

int
main(int argc, char** argv) {
	CtrA	a;
	CtrB	b;

	try {
		_parse_args(a, b, argc - 1, argv + 1);
		_sort(a, b);
	} catch (std::logic_error& e) {
		std::cerr << "Error: " << e.what() << '\n';
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static void
_parse_args(CtrA& a, CtrB& b, int n, char** cstrs) {
	size_t	pos;

	for (int i = n; i > 0; --i) {
		std::string const	str(cstrs[i - 1]);
		unsigned long const	number = std::stoul(str, &pos);

		if (pos != str.size())
			throw (PMMException("invalid argument"));
		a.push_front(number);
		b.push_front(number);
	}
}

static void
_sort(CtrA& a, CtrB& b) {
	_ctr_print_line(a, "Before: ");

	clock_t const	ta = ford_johnson(a);
	clock_t const	tb = ford_johnson(b);

	_ctr_print_line(a, "After (std::deque): ");
	_ctr_print_line(b, "After (std::list):  ");
	std::cout << "std::deque of length "
		<< std::to_string(a.size())
		<< " was sorted in " << std::to_string(ta) << " μs.\n"
		"std::list of length " << b.size() << " was sorted in "
		<< std::to_string(tb) << " μs.\n";
}
