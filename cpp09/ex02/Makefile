CXX				=	c++
CXXFLAGS		=	-Wall -Wextra -Werror
CXXFLAGS		+=	-std=c++98

PRE_OPT			=	-MMD -MP
INCLUDE			=	-I$(INCLUDES_DIR)

SRCS_DIR		=	./srcs
OBJS_DIR		=	./objs
INCLUDES_DIR	=	./inc
TESTS_DIR		=	./tests

SRCS			=	PmergeMe.cpp

MAIN_SRCS		=	main.cpp

TEST_SRCS		=	main_test.cpp \
					test_jacobsthal.cpp


OBJS			=	$(patsubst %.o, $(OBJS_DIR)/%.o, $(SRCS:.cpp=.o))
DEPS			=	$(OBJS:.o=.d)

RM				=	rm -rf

NAME			=	PmergeMe
MAIN_OBJS		=	$(patsubst %.cpp, $(OBJS_DIR)/%.o, $(SRCS) $(MAIN_SRCS))

$(NAME): $(OBJS_DIR) $(MAIN_OBJS)
	$(CXX) $(MAIN_OBJS) -o $@

TEST_TARGET	=	PmergeMe_test
TEST_OBJS	=	$(patsubst %.cpp, $(OBJS_DIR)/%.o, $(SRCS) $(TEST_SRCS))

test: $(OBJS_DIR) $(TEST_TARGET)
	./$(TEST_TARGET)

$(TEST_TARGET): $(TEST_OBJS)
	$(CXX) $(TEST_OBJS) -o $@

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDE) $(PRE_OPT) -c $< -o $@

$(OBJS_DIR)/%.o: tests/%.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDE) $(PRE_OPT) -c $< -o $@

.DEFAULT_GOAL	=	all
.PHONY:	all clean fclean re test
all:	$(NAME)

clean:
	$(RM) $(OBJS_DIR)

fclean:	clean
	$(RM) $(NAME) $(TEST_TARGET)

re:	fclean all

-include $(DEPS)
