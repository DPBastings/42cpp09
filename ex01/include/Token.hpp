#ifndef ELEMENT_HPP
# define ELEMENT_HPP

# include <iostream>
# include <string>

class Element:
public:
	enum class Type: int {
		add, subtract, multiply, divide, number
	};

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
	Type	type() const;
	int		value() const;

private:
	Type	_type;
	int		_value;
}; // class Element

std::istream&	operator>>(std::istream&, Element&);
std::ostream&	operator<<(std::ostream&, Element const&);

#endif // ELEMENT_HPP	
