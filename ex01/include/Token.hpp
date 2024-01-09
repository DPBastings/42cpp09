#ifndef ELEMENT_HPP
# define ELEMENT_HPP

# include <iostream>
# include <string>

class aToken:
public:
	Element();
	~Element();
	Element(Element const&);
	Element(int, Type = Type::number);

	Element&	operator=(Element const&);
	Element		operator+(Element const&) const;
	Element		operator-(Element const&) const;
	Element		operator*(Element const&) const;
	Element		operator/(Element const&) const;
				operator int() const;
				operator std::string() const;

	void	operate(int&, Element const&) const;
	int		operate(Element const&, Element const&) const;
}; // class Element

class Operator: public aToken {
public:
	using aToken::aToken();
}; // class Operator

class Addition: public Operator {
public:
	using Operator::Operator();
}; // class Addition

class Subtraction: public Operator {
public:
	using Operator::Operator();
}; // class Subtraction

class Multiplication: public Operator {
public:
	using Operator::Operator();
}; // class Multiplication

class Division: public Operator {
public:
	using Operator::Operator();
}; // class Division

class Integer: public aToken {
public:
	Integer(int);

	int	value() const noexcept;

private:
	int	_value;
}; // class Integer

std::istream&	operator>>(std::istream&, Element&);
std::ostream&	operator<<(std::ostream&, Element const&);

#endif // ELEMENT_HPP	
