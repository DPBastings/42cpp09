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

#endif // PMM_TPP
