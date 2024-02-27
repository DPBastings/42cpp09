#include "PMM.hpp"

static void	_ford_johnson_sort(CtrA&);
static void	_fj_split(CtrA const&, size_t, CtrA&, CtrA&);
static void	_fj_merge(CtrA&, CtrA const&, CtrA const&);

clock_t	ford_johnson(CtrA& ctr) {
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
_ford_johnson_sort(CtrA& ctr) {
	size_t const	size = std::distance(ctr.begin(), ctr.end());
	CtrA			left;
	CtrA			right;

	if (size < 2)
		return;
	_fj_split(ctr, size, left, right);
	_ford_johnson_sort(left);
	_ford_johnson_sort(right);
	_fj_merge(ctr, left, right);
}

static void
_fj_split(CtrA const& ctr, size_t size, CtrA& left, CtrA& right) {
	size_t	middle = size / 2;
	auto	it = ctr.begin();

	for (size_t i = 0; i < middle; ++i)
		left.push_front(*(it++));
	for (auto i = middle; i < size; ++i)
		right.push_front(*(it++));
}

static void
_fj_merge(CtrA& ctr, CtrA const& left, CtrA const& right) {
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
