#ifndef PMM_HPP
# define PMM_HPP

# include <ctime>
# include <deque>
# include <iostream>
# include <list>
# include <stdexcept>
# include <utility>

template<typename T>
using BaseCtrA = std::deque<T>;
template<typename T>
using BaseCtrB = std::list<T>;

using CtrA = BaseCtrA<unsigned long>;
using CtrB = BaseCtrB<unsigned long>;

using PairCtrA = BaseCtrA<std::pair<unsigned long, unsigned long>>;
using PairCtrB = BaseCtrB<std::pair<unsigned long, unsigned long>>;

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

size_t	jacobsthal(size_t);

# include "PMM.tpp"

#endif // PMM_HPP
