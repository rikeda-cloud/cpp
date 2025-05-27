TARGET			=	megaphone

CXX				=	c++
CXXFLAGS		=	-Wall -Wextra -Werror
CXXFLAGS		+=	-std=c++98
RM				=	rm -rf

SRCS			=	megaphone.cpp
OBJS			=	$(SRCS:%.cpp=%.o)

$(TARGET)	: $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@

test : $(TARGET)
	./test.sh

%.o: %.c
	$(CXX) $(CXXFLAGS) -c $^ -o $@

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
