NAME			=	diamondtrap

CC				=	c++
CFLAGS			=	-Wall -Wextra -Werror
CFLAGS			+=	-std=c++98

PRE_OPT			=	-MMD -MP
INCLUDE			=	-I$(INCLUDES_DIR)

SRCS_DIR		=	./srcs
OBJS_DIR		=	./objs
INCLUDES_DIR	=	./inc

SRCS			=	ClapTrap.cpp \
					ScavTrap.cpp \
					FragTrap.cpp \
					DiamondTrap.cpp \
					main.cpp

OBJS			=	$(patsubst %.o, $(OBJS_DIR)/%.o, $(SRCS:.cpp=.o))
DEPS			=	$(OBJS:.o=.d)

RM				=	rm -rf

$(OBJS_DIR)	: % :
	@mkdir -p $@

$(NAME)	: $(OBJS_DIR) $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDE) $(OBJS) -o $@

$(OBJS_DIR)/%.o	:	$(SRCS_DIR)/%.cpp
	$(CC) $(CFLAGS) $(INCLUDE) $(PRE_OPT) -o $@ -c $<

.DEFAULT_GOAL	=	all
.PHONY:	all
all:	$(NAME)

.PHONY:	clean
clean:
	$(RM) $(OBJS_DIR)

.PHONY:	fclean
fclean:	clean
	$(RM) $(NAME)

.PHONY:	re
re:	fclean all

-include $(DEPS)
