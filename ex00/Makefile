NAME		:= btc

SRC_DIR		:= ./source/
OBJ_DIR		:= ./object/
HDR_DIR		:= ./include/

SRC_FILES	:= main.cpp\
			BitcoinExchange.cpp\
			DatabaseLine.cpp\
			Date.cpp\
			Query.cpp\
			parse_database.cpp\
			parse_exception.cpp\
			parse_query.cpp

OBJ_FILES	:= $(patsubst %.cpp,%.o,$(SRC_FILES))
HDR_FILES	:= BitcoinExchange.hpp\
			DatabaseLine.hpp\
			Date.hpp\
			Query.hpp\
			parse.hpp

CC			:= g++
CFLAGS		:= -Wall -Wextra -Werror -I$(HDR_DIR) -g -fsanitize=address

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(addprefix $(OBJ_DIR),$(OBJ_FILES))
	@$(CC) $(CFLAGS) $^ -o $@

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp $(addprefix $(HDR_DIR),$(HDR_FILES))
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(DEPFLAGS) -c $< -o $@

clean:
	@rm -f $(addprefix $(OBJ_DIR),$(OBJ_FILES))

fclean: clean
	@rm -f $(NAME)

re: fclean all
