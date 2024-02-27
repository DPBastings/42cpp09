#include "PMM.hpp"

PMMException::PMMException():
	std::logic_error("Something went wrong") {
}

PMMException::PMMException(char const *cstr):
	std::logic_error(cstr) {
}
