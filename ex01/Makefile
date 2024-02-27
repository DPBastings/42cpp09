NAME		:= RPN

SRC_DIR		:= ./source/
OBJ_DIR		:= ./object/
HDR_DIR		:= ./include/

SRC_FILES	:= main.cpp\
			Expression.cpp\
			Expression_eval.cpp\
			Expression_except.cpp\
			Integer.cpp\
			Operator.cpp\
			Token.cpp\
			RPN.cpp

OBJ_FILES	:= $(patsubst %.cpp,%.o,$(SRC_FILES))
HDR_FILES	:= RPN.hpp\
			Token.hpp\
			fwd.hpp

CXX			:= c++
CXXFLAGS	+= -std=c++11 -Wall -Wextra -Werror -I$(HDR_DIR) -g -fsanitize=address

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(addprefix $(OBJ_DIR),$(OBJ_FILES))
	@$(CXX) $(CXXFLAGS) $^ -o $@

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp $(addprefix $(HDR_DIR),$(HDR_FILES))
	@mkdir -p $(OBJ_DIR)
	@$(CXX) $(CXXFLAGS) $(DEPFLAGS) -c $< -o $@

clean:
	@rm -f $(addprefix $(OBJ_DIR),$(OBJ_FILES))

fclean: clean
	@rm -f $(NAME)

re: fclean all
