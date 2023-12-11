#include "parse.hpp"

#include <ctime>
#include <iostream>

using parse::ParseException;

std::istream&
operator>>(std::istream& is, DatabaseLine& dbline) {
	std::string	segments[2];

	for (size_t i = 0; i < 2; i++)
		if (!std::getline(is, segments[i], ','))
			throw (ParseException(""));

	Date const	date(segments[0]);
	float const	rate = stof(segments[1]);

	dbline = DatabaseLine(date, rate);
	return (is);
}

std::ostream&
operator<<(std::ostream& os, DatabaseLine const& dbline) {
	os << dbline.date() << "," << dbline.rate();
	return (os);
}
