NAME			=	dreams
CC				=	c++
CFLAGS			=	-Wall -Wextra -Werror
CFLAGS			+=	-std=c++98
SRCS			=	tests.cpp \
					Account.cpp

RM				=	rm -rf
OBJS			=	$(SRCS:%.cpp=%.o)

$(NAME)	: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

test_diff: 
	./test/test.sh

.DEFAULT_GOAL	=	all
.PHONY:	all
all:	$(NAME)

.PHONY:	clean
clean:
	$(RM) $(OBJS)

.PHONY:	fclean
fclean:	clean
	$(RM) $(NAME)

.PHONY:	re
re:	fclean all
