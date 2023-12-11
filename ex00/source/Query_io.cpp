#include "Query.hpp"
#include "parse.hpp"

#include <iostream>
#include <string>

using parse::ParseException;

std::istream&
operator>>(std::istream& is, Query& query) {
	std::string	segments[2];

	for (size_t i = 0; i < 2; ++i) {
		std::getline(is, segments[i], '|');
		if (segments[i].length() == 0)
			throw (ParseException(""));
	}
	Date	date(segments[0]);
	float	value = std::stof(segments[1]);

	if (value < 0)
		throw (ParseException("not a positive number."));
	else if (value >= 1000)
		throw (ParseException("too large a number."));
	query = Query(date, value);
	return (is);
}

std::ostream&
operator<<(std::ostream& os, Query const& query) {
	os << query.date() << " | " << query.value();
	return (os);
}
