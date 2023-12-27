NAME			=	megaphone
CC				=	c++
CFLAGS			=	-Wall -Wextra -Werror
CFLAGS			+=	-std=c++98
RM				=	rm -rf

SRCS			=	megaphone.cpp

OBJS			=	$(SRCS:%.cpp=%.o)

$(NAME)	: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

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
