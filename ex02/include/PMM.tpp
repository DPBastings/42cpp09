#ifndef PMM_TPP
# define PMM_TPP

# ifndef PMM_HPP
#  error "Include file in PMM.hpp"
# endif // PMM_HPP

template<typename CTR>
void
ctr_print(CTR const& ctr, std::ostream& os) {
	for (auto const& item: ctr)
		os << std::to_string(item) << ' ';
}

template<typename CTR>
clock_t
ford_johnson(CTR& ctr) {
	clock_t const	start = clock();

	if (start == -1)
		throw (PMMException("couldn't determine time"));
	ford_johnson_sort(ctr);

	clock_t const	end = clock();

	if (end == -1)
		throw (PMMException("couldn't determine time"));
	return (end - start);
}

#endif // PMM_TPP
