#include "PMM.hpp"

static void	_ford_johnson_sort(CtrB&);
//static void	_fj_split(CtrB const&, size_t, CtrB&, CtrB&);
//static void	_fj_merge(CtrB&, CtrB const&, CtrB const&);

clock_t	ford_johnson(CtrB& ctr) {
	clock_t const	start = clock();

	if (start == -1)
		throw (PMMException("couldn't determine time"));
	_ford_johnson_sort(ctr);

	clock_t const	end = clock();

	if (end == -1)
		throw (PMMException("couldn't determine time"));
	return (end - start);
}

static void
_ford_johnson_sort(CtrB&) {
	return;
	/*size_t const	size = ctr.size();
	CtrB			left;
	CtrB			right;

	if (size < 2)
		return;
	_fj_split(ctr, size, left, right);
	_fj_merge(ctr, left, right);*/
}
/*
static void
_fj_split(CtrB const& ctr, size_t size, CtrB& left, CtrB& right) {
	auto const	middle = ctr.begin() + (size / 2);

	for (auto it = ctr.begin(); it < middle; ++it)
		left.push_front(*it);
	for (auto it = middle; it < ctr.end(); ++it)
		right.push_front(*it);
}

static void
_fj_merge(CtrB& ctr, CtrB const& left, CtrB const& right) {
	auto itl = left.begin();
	auto itr = right.begin();

	ctr.clear();
	while (itl != left.end() && itr != right.end()) {
		if (*itl < *itr)
			ctr.push_front((*itl)++);
		else
			ctr.push_front((*itr)++);
	}
	while (itl != left.end())
		ctr.push_front((*itl)++);
	while (itr != right.end())
		ctr.push_front((*itr)++);
	list.reverse();
}*/
