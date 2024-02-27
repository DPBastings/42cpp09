#ifndef PMM_HPP
# define PMM_HPP

# include <ctime>
# include <forward_list>
# include <iostream>
# include <list>
# include <stdexcept>

using CtrA = std::forward_list<unsigned>;
using CtrB = std::list<unsigned>;

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

clock_t	ford_johnson(CtrA&);
clock_t	ford_johnson(CtrB&);

# include "PMM.tpp"

#endif // PMM_HPP
