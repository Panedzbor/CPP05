COMPILER = c++
FLAGS = -g -Wall -Wextra -Werror -std=c++98

NAME = a.out
SRCS = $(wildcard *.cpp)
OBJ_DIR = obj
OBJS = $(SRCS:%.cpp=$(OBJ_DIR)/%.o)
INCLUDES = $(wildcard *.hpp)
RM = rm -rf

.PHONY: all clean fclean re run

all: $(NAME)

$(NAME): $(OBJS)
	$(COMPILER) $(FLAGS) -o $@ $^

$(OBJ_DIR)/%.o: %.cpp $(INCLUDES)
	@mkdir -p $(dir $@)
	$(COMPILER) $(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

run: all
	valgrind ./$(NAME)