CXX				=	c++
CXXFLAGS		=	-Wall -Wextra -Werror
CXXFLAGS		+=	-std=c++98

PRE_OPT			=	-MMD -MP
INCLUDE			=	-I$(INCLUDES_DIR)

SRCS_DIR		=	./srcs
OBJS_DIR		=	./objs
INCLUDES_DIR	=	./inc
TESTS_DIR		=	./tests

SRCS			=	AConverter.cpp \
					IntConverter.cpp \
					CharConverter.cpp \
					FloatConverter.cpp \
					DoubleConverter.cpp \
					IScalar.cpp \
					IntScalar.cpp \
					CharScalar.cpp \
					FloatScalar.cpp \
					DoubleScalar.cpp \
					UnknownScalar.cpp \
					ScalarConverter.cpp

MAIN_SRCS		=	main.cpp

TEST_SRCS		=	main_test.cpp \
					test_utils.cpp

OBJS			=	$(patsubst %.o, $(OBJS_DIR)/%.o, $(SRCS:.cpp=.o))
DEPS			=	$(OBJS:.o=.d)

RM				=	rm -rf

TARGET			=	convert
MAIN_OBJS		=	$(patsubst %.cpp, $(OBJS_DIR)/%.o, $(SRCS) $(MAIN_SRCS))

$(TARGET): $(OBJS_DIR) $(MAIN_OBJS)
	$(CXX) $(CXXFLAGS) $(INCLUDE) $(MAIN_OBJS) -o $@

TEST_TARGET	=	convert_test
TEST_OBJS	=	$(patsubst %.cpp, $(OBJS_DIR)/%.o, $(SRCS) $(TEST_SRCS))

test: $(OBJS_DIR) $(TEST_TARGET)
	./$(TEST_TARGET)

$(TEST_TARGET): $(TEST_OBJS)
	$(CXX) $(CXXFLAGS) $(INCLUDE) $(TEST_OBJS) -o $@

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDE) $(PRE_OPT) -c $< -o $@

$(OBJS_DIR)/%.o: tests/%.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDE) $(PRE_OPT) -c $< -o $@

.DEFAULT_GOAL	=	all
.PHONY:	all clean fclean re test
all:	$(TARGET)

clean:
	$(RM) $(OBJS_DIR)

fclean:	clean
	$(RM) $(TARGET) $(TEST_TARGET)

re:	fclean all

-include $(DEPS)
