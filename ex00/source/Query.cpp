#include "Query.hpp"

#include <ctime>

// Constructor

Query::Query():
	_date(0),
	_value(0.0) {
}

Query::~Query() {
}

Query::Query(Query const& that):
	_date(that._date),
	_value(that._value) {
}

Query::Query(std::time_t date, float value):
	_date(date),
	_value(value) {
}

// Operator

Query&
Query::operator=(Query const&) {
	return (*this);
}

// Public methods

std::time_t
Query::date() const {
	return (_date);
}

float
Query::value() const {
	return (_value);
}
