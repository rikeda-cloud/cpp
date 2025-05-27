TARGET			=	Fixed3

CXX				=	c++
CXXFLAGS		=	-Wall -Wextra -Werror

PRE_OPT			=	-MMD -MP
INCLUDE			=	-I$(INCLUDES_DIR)

SRCS_DIR		=	./srcs
OBJS_DIR		=	./objs
INCLUDES_DIR	=	./inc

SRCS			=	Fixed.cpp

ifeq ($(MAKECMDGOALS), test)
	CXXFLAGS	+=	-std=c++14
	INCLUDE		+=	-I/Users/rikeda/.local/include
	LINKER		=	-L/Users/rikeda/.local/lib/ -lgtest -lgtest_main
	SRCS		+=	GoogleTest.cpp
else
	CXXFLAGS	+=	-std=c++98
	SRCS		+=	main.cpp
endif

OBJS			=	$(patsubst %.o, $(OBJS_DIR)/%.o, $(SRCS:.cpp=.o))
DEPS			=	$(OBJS:.o=.d)

RM				=	rm -rf


$(OBJS_DIR)	: % :
	@mkdir -p $@

$(TARGET)	: $(OBJS_DIR) $(OBJS)
	$(CXX) $(CXXFLAGS) $(LINKER) $(INCLUDE) $(OBJS) -o $@

$(OBJS_DIR)/%.o	:	$(SRCS_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDE) $(PRE_OPT) -o $@ -c $<

test:	$(TARGET)

.DEFAULT_GOAL	=	all
.PHONY:	all
all:	$(TARGET)

.PHONY:	clean
clean:
	$(RM) $(OBJS_DIR)

.PHONY:	fclean
fclean:	clean
	$(RM) $(TARGET)

.PHONY:	re
re:	fclean all

-include $(DEPS)
