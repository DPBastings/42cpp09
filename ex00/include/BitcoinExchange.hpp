#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP

# include "DatabaseLine.hpp"
# include "Query.hpp"

# include <vector>

using Database = std::vector<DatabaseLine>;

constexpr char	database_path[] = "./data.csv";

Database	open_database(char const* path = database_path);

void		process_queries(char const*, Database const&);

#endif // BITCOIN_EXCHANGE_HPP
