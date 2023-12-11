#include "Query.hpp"

// Constructors

Query::Query():
	_date(0), _value(0.0) {}

Query::~Query() {}

Query::Query(Query const& that):
	_date(that._date), _value(that._value) {}

Query::Query(Date date, float value):
	_date(date), _value(value) {}

// Operators

Query&
Query::operator=(Query const& that) {
	if (this == &that)
		return (*this);
	_date = that._date;
	_value = that._value;
	return (*this);
}

// Public methods

Date
Query::date() const {
	return (_date);
}

float
Query::value() const {
	return (_value);
}
