#include "DatabaseLine.hpp"

#include <ctime>

// Constructors

DatabaseLine::DatabaseLine():
	_date(),
	_rate() {
}

DatabaseLine::~DatabaseLine() {
}

DatabaseLine::DatabaseLine(DatabaseLine const& that):
	_date(that._date),
	_rate(that._rate) {
}

DatabaseLine::DatabaseLine(Date date, float rate):
	_date(date),
	_rate(rate) {
}

// Operators

DatabaseLine&
DatabaseLine::operator=(DatabaseLine const& that) {
	if (this == &that)
		return (*this);
	_date = that._date;
	_rate = that._rate;
	return (*this);
}

// Public methods

Date
DatabaseLine::date() const {
	return (_date);
}

float
DatabaseLine::rate() const {
	return (_rate);
}
