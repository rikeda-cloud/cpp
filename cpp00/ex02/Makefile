TARGET			=	dreams

CXX				=	c++
CXXFLAGS		=	-Wall -Wextra -Werror
CXXFLAGS		+=	-std=c++98
SRCS			=	tests.cpp \
					Account.cpp

RM				=	rm -rf
OBJS			=	$(SRCS:%.cpp=%.o)

$(TARGET)	: $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@

%.o: %.c
	$(CXX) $(CXXFLAGS) -c $^ -o $@

test_diff: $(TARGET)
	./test/test.sh

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
