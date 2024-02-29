#include "PMM.hpp"

static void	_fj_split(CtrB const&, size_t, CtrB&, CtrB&);
static void	_fj_merge(CtrB&, CtrB const&, CtrB const&);

void
ford_johnson_sort(CtrB& ctr) {
	size_t const	size = ctr.size();
	CtrB			left;
	CtrB			right;

	if (size < 2)
		return;
	_fj_split(ctr, size, left, right);
	ford_johnson_sort(left);
	ford_johnson_sort(right);
	_fj_merge(ctr, left, right);
}

static void
_fj_split(CtrB const& ctr, size_t size, CtrB& left, CtrB& right) {
	size_t const	middle = size / 2;
	auto			it = ctr.begin();

	for (size_t i = 0; i < middle; ++i)
		left.push_front(*(it++));
	for (size_t i = middle; i < size; ++i)
		right.push_front(*(it++));
}

static void
_fj_merge(CtrB& ctr, CtrB const& left, CtrB const& right) {
	auto itl = left.begin();
	auto itr = right.begin();

	ctr.clear();
	while (itl != left.end() && itr != right.end()) {
		if (*itl < *itr)
			ctr.push_front(*(itl++));
		else
			ctr.push_front(*(itr++));
	}
	while (itl != left.end())
		ctr.push_front(*(itl++));
	while (itr != right.end())
		ctr.push_front(*(itr++));
	ctr.reverse();
}
