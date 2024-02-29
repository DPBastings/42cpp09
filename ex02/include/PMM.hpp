#ifndef PMM_HPP
# define PMM_HPP

# include <ctime>
# include <forward_list>
# include <iostream>
# include <list>
# include <stdexcept>

using CtrA = std::forward_list<unsigned long>;
using CtrB = std::list<unsigned long>;

template<typename CTR>
void	ctr_print(CTR const&, std::ostream& os);

class PMMException: public std::logic_error {
public:
	PMMException();
	~PMMException() = default;
	PMMException(PMMException const&) = default;
	PMMException(PMMException&&) = default;
	PMMException(char const*);
	
	PMMException&	operator=(PMMException const&) = default;
	PMMException&	operator=(PMMException&&) = default;
}; // class PMMException

template<typename CTR>
clock_t	ford_johnson(CTR&);

void	ford_johnson_sort(CtrA&);
void	ford_johnson_sort(CtrB&);

# include "PMM.tpp"

#endif // PMM_HPP
