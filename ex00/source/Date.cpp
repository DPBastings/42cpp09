#include "Date.hpp"
#include "parse.hpp"

#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <string>
#include <sstream>

static std::time_t	string_to_time(std::string const&);

// Constructors

Date::Date():
	_data() {
}

Date::~Date() {
}

Date::Date(Date const& that):
	_data(that._data) {
}

Date::Date(std::time_t data):
	_data(data) {
}

Date::Date(std::string const& str):
	_data(string_to_time(str)) {
}

// Operators

Date&
Date::operator=(Date const& that) {
	if (this == &that)
		return (*this);
	_data = that._data;
	return (*this);
}

bool
Date::operator==(Date const& that) const {
	return (_data == that._data);
}

bool
Date::operator<(Date const& that) const {
	return (_data < that._data);
}

bool
Date::operator>(Date const& that) const {
	return (_data > that._data);
}

bool
Date::operator<=(Date const& that) const {
	return (_data <= that._data);
}

bool
Date::operator>=(Date const& that) const {
	return (_data >= that._data);
}

// Conversion operators

Date::operator std::string() const {
	constexpr size_t	bufsize = 128;

	char			buf[bufsize];
	std::tm const*	tm = std::localtime(&_data);
	std::strftime(buf, bufsize, "%Y-%m-%d", tm);
	return (std::string(buf));
}

// Public methods

std::time_t
Date::data() const {
	return (_data);
}

// Non-member functions

std::istream&
operator>>(std::istream& is, Date& obj) {
	std::tm	tm;

	std::memset(&tm, '\0', sizeof(tm));
	is >> std::get_time(&tm, "%Y-%m-%d");
	obj = Date(mktime(&tm));
	return (is);
}

std::ostream&
operator<<(std::ostream& os, Date const& obj) {
	os << std::string(obj);
	return (os);
}

// Helper functions

std::time_t
string_to_time(std::string const& string) {
	std::istringstream	iss(string);
	std::tm				tm;

	std::memset(&tm, '\0', sizeof(tm));
	iss >> std::get_time(&tm, "%Y-%m-%d");
	if (iss.fail())
		throw (parse::ParseException("incorrect date format"));
	return (mktime(&tm));
}
