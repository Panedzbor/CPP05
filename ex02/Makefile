COMPILER = c++
FLAGS = -g -Wall -Wextra -Werror -std=c++98

NAME = a.out
SRCS = $(wildcard *.cpp)
OBJ_DIR = obj
OBJS = $(SRCS:%.cpp=$(OBJ_DIR)/%.o)
INCLUDES = $(wildcard *.hpp)
RM = rm -rf
TESTKIT_DIR = testkit
TESTKIT_LIB = $(TESTKIT_DIR)/testkit.a
TESTKIT_LIB_FLAGS = -I$(TESTKIT_DIR)

.PHONY: all clean fclean re run testkit

all: $(NAME)

$(NAME): $(OBJS) testkit
	$(COMPILER) $(FLAGS) -o $@ $(OBJS) $(TESTKIT_LIB)

testkit:
	$(MAKE) -C $(TESTKIT_DIR)

$(OBJ_DIR)/%.o: %.cpp $(INCLUDES)
	@mkdir -p $(dir $@)
	$(COMPILER) $(TESTKIT_LIB_FLAGS) $(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ_DIR)
	$(MAKE) -C $(TESTKIT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(TESTKIT_DIR) fclean
	$(RM) *_shrubbery

re: fclean all

run: all
	valgrind ./$(NAME)
