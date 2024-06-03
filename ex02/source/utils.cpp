#include "PMM.hpp"

size_t
jacobsthal(size_t n) {
	if (n < 2)
		return (n);
	return (jacobsthal(n - 1) + 2 * jacobsthal(n - 2));
}