#ifndef ELEMENT_HPP
# define ELEMENT_HPP

# include "fwd.hpp"

# include <iostream>
# include <string>

class aToken {
public:
	aToken() = default;
	virtual ~aToken() = default;
	aToken(aToken const&) = default;
	aToken(aToken&&) = default;

	aToken&	operator=(aToken const&) = default;
	aToken&	operator=(aToken&&) = default;
			virtual operator std::string() const = 0;
}; // class Token

std::ostream&	operator<<(std::ostream&, aToken const&);

class Integer: public aToken {
public:
	Integer() = default;
	~Integer() = default;
	Integer(Integer const&) = default;
	Integer(Integer&&) = default;
	Integer(char);
	Integer(int);

	Integer&	operator=(Integer const&) = default;
	Integer&	operator=(Integer&&) = default;
				operator int() const noexcept;
				operator std::string() const;

	Integer&	calculate(Integer const& rhs, aToken const* op);
	int			value() const noexcept;
	int&		value() noexcept;

private:
	int	_value;
}; // class Integer

class Operator: public aToken {
public:
	using aToken::aToken;
	virtual ~Operator() = default;
	Operator(Operator const&) = default;
	Operator(Operator&&) = default;

	Operator&	operator=(Operator const&) = default;
	Operator&	operator=(Operator&&) = default;
				virtual operator std::string() const = 0;

	virtual Integer	operate(Integer const&, Integer const&) const noexcept = 0;
}; // class Operator

class Addition: public Operator {
public:
	using Operator::Operator;
	~Addition() = default;
	Addition(Addition const&) = default;
	Addition(Addition&&) = default;

	Addition&	operator=(Addition const&) = default;
	Addition&	operator=(Addition&&) = default;
				operator std::string() const;

	Integer	operate(Integer const&, Integer const&) const noexcept;
}; // class Addition

class Subtraction: public Operator {
public:
	using Operator::Operator;
	~Subtraction() = default;
	Subtraction(Subtraction const&) = default;
	Subtraction(Subtraction&&) = default;

	Subtraction&	operator=(Subtraction const&) = default;
	Subtraction&	operator=(Subtraction&&) = default;
					operator std::string() const;

	Integer	operate(Integer const&, Integer const&) const noexcept;
}; // class Subtraction

class Multiplication: public Operator {
public:
	using Operator::Operator;
	~Multiplication() = default;
	Multiplication(Multiplication const&) = default;
	Multiplication(Multiplication&&) = default;

	Multiplication&	operator=(Multiplication const&) = default;
	Multiplication&	operator=(Multiplication&&) = default;
					operator std::string() const;

	Integer	operate(Integer const&, Integer const&) const noexcept;
}; // class Multiplication

class Division: public Operator {
public:
	using Operator::Operator;
	~Division() = default;
	Division(Division const&) = default;
	Division(Division&&) = default;

	Division&	operator=(Division const&) = default;
	Division&	operator=(Division&&) = default;
				operator std::string() const;

	Integer	operate(Integer const&, Integer const&) const noexcept;
}; // class Division

#endif // ELEMENT_HPP	
