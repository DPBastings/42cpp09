#ifndef DATABASE_LINE_HPP
# define DATABASE_LINE_HPP

# include <ctime>

class DatabaseLine {
public:
	DatabaseLine();
	~DatabaseLine();
	DatabaseLine(DatabaseLine const&);
	DatabaseLine(std::time_t, float);
	
	DatabaseLine&	operator=(DatabaseLine const&);

	std::time_t	date() const;
	float		rate() const;
private:
	std::time_t	_date;
	float		_rate;
};

#endif // DATABASE_LINE_HPP
