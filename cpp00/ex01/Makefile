NAME			=	phonebook

CC				=	c++
CFLAGS			=	-Wall -Wextra -Werror -g
CFLAGS			+=	-std=c++98

PRE_OPT			=	-MMD -MP
INCLUDE			=	-I$(INCLUDES_DIR)

SRCS_DIR		=	./srcs
OBJS_DIR		=	./objs
INCLUDES_DIR	=	./inc

SRCS			=	PhoneBook/PhoneBook.cpp \
					Contact/Contact.cpp \
					main.cpp

OBJS			=	$(patsubst %.o, $(OBJS_DIR)/%.o, $(SRCS:.cpp=.o))
DEPS			=	$(OBJS:.o=.d)
OBJS_SUBDIRS 	=	$(sort $(dir $(OBJS)))

RM				=	rm -rf

$(OBJS_DIR)	: % :
	@mkdir -p $@

$(OBJS_SUBDIRS) : % :
	@mkdir -p $@

$(NAME)	: $(OBJS_DIR) $(OBJS_SUBDIRS) $(OBJS)
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
