TARGET			=	ThisIsBrain

CXX				=	c++
CXXFLAGS		=	-Wall -Wextra -Werror
CXXFLAGS		+=	-std=c++98
SRCS			=	main.cpp

OBJS			=	$(SRCS:%.cpp=%.o)

RM				=	rm -rf

$(TARGET)	: $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@

.DEFAULT_GOAL	=	all
.PHONY:	all
all:	$(TARGET)

.PHONY:	clean
clean:
	$(RM) $(OBJS)

.PHONY:	fclean
fclean:	clean
	$(RM) $(TARGET)

.PHONY:	re
re:	fclean all

-include $(DEPS)
