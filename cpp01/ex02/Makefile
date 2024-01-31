NAME			=	ThisIsBrain

CC				=	c++
CFLAGS			=	-Wall -Wextra -Werror
CFLAGS			+=	-std=c++98
SRCS			=	main.cpp

OBJS			=	$(SRCS:%.cpp=%.o)

RM				=	rm -rf

$(NAME)	: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

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

-include $(DEPS)
