#include "PMM.hpp"

#include <iterator>

static PairCtrA	_fj_get_pairs(CtrA const&, CtrA&);
static void		_fj_merge_sort_pairs(PairCtrA&);
static void		_fj_split(PairCtrA const&, size_t, PairCtrA&, PairCtrA&);
static void		_fj_merge(PairCtrA&, PairCtrA const&, PairCtrA const&);
static void		_fj_unpair(CtrA&, CtrA&, PairCtrA const&);
static void		_fj_insert(CtrA&, CtrA const&);
static void		_fj_bin_insert(CtrA&, size_t, size_t, unsigned long);

void
ford_johnson_sort(CtrA& ctr) {
	CtrA		main;
	CtrA		pend;
	PairCtrA	pairs = _fj_get_pairs(ctr, pend);

	_fj_merge_sort_pairs(pairs);
	_fj_unpair(main, pend, pairs);
	ctr_print(main, std::cout);
	std::cout << '\n';
	ctr_print(pend, std::cout);
	std::cout << '\n';
	_fj_insert(main, pend);
	ctr = std::move(main);
}

PairCtrA	_fj_get_pairs(CtrA const& ctr, CtrA& pend) {
	PairCtrA	pairs;

	for (auto it = ctr.begin(); it != ctr.end(); std::advance(it, 2)) {
		auto	next = std::next(it);
		if (next == ctr.end()) {
			pend.push_front(*it);
			break;
		}
		pairs.push_front(std::make_pair(*it, *next));
	}
	for (auto& pair: pairs)
		if (pair.first < pair.second)
			std::swap(pair.first, pair.second);
	return (pairs);
}

void
_fj_merge_sort_pairs(PairCtrA& pairs) {
	size_t const	size = std::distance(pairs.begin(), pairs.end());
	PairCtrA		left;
	PairCtrA		right;

	if (size < 2)
		return;
	_fj_split(pairs, size, left, right);
	_fj_merge_sort_pairs(left);
	_fj_merge_sort_pairs(right);
	_fj_merge(pairs, left, right);
}

static void
_fj_split(PairCtrA const& ctr, size_t size, PairCtrA& left, PairCtrA& right) {
	size_t	middle = size / 2;
	auto	it = ctr.begin();

	for (size_t i = 0; i < middle; ++i)
		left.push_front(*(it++));
	for (auto i = middle; i < size; ++i)
		right.push_front(*(it++));
}

static void
_fj_merge(PairCtrA& ctr, PairCtrA const& left, PairCtrA const& right) {
	auto itl = left.begin();
	auto itr = right.begin();

	ctr.clear();
	while (itl != left.end() && itr != right.end()) {
		if (itl->first > itr->first)
			ctr.push_back(*(itl++));
		else
			ctr.push_back(*(itr++));
	}
	while (itl != left.end())
		ctr.push_back(*(itl++));
	while (itr != right.end())
		ctr.push_back(*(itr++));
}

static void
_fj_unpair(CtrA& main, CtrA& pend, PairCtrA const& pairs) {
	for (auto const& pair: pairs) {
		main.push_front(pair.first);
		pend.push_front(pair.second);
	}
}

static void
_fj_insert(CtrA& main, CtrA const& pend) {
	main.push_front(pend.front());	// First pending element can always go at the front.

	size_t	n_inserted = 1;
	size_t	i = 0;		// Index of pend that is currently accessed.
	size_t	jcth_i = 1;	// Index of the current Jacobsthal number.

	while (true) {
		size_t const	fwd = 2 * jacobsthal(jcth_i++);
		size_t const	left_bound = i; // Elements of pend will be read right-to-left until this index.
		if (left_bound + fwd >= pend.size()) // Jacobsthal capacity exceeds the number of pending elements.
			break;
		i = left_bound + fwd;
		while (i > left_bound) {
			_fj_bin_insert(main, 0, i + n_inserted - 1, pend[i]);
			++n_inserted;
			--i;
		}
		i += fwd;
	}

	size_t const	left_bound = i;

	i = pend.size() - 1;
	while (i > left_bound) {
		_fj_bin_insert(main, 0, main.size() - 1, pend[i]);
		--i;
	}
}

static void
_fj_bin_insert(CtrA& main, size_t start, size_t end, unsigned long num) {
	auto 	startit = std::next(main.begin(), start);

	if (start == end) {
		if (*startit > num)
			main.insert(startit, num);
		else
			main.insert(std::next(startit), num);
		return;
	}
	size_t	middle = (start + end) / 2;
	
	if (main[middle] > num)
		_fj_bin_insert(main, start, middle, num);
	else
		_fj_bin_insert(main, middle + 1, end, num);
}