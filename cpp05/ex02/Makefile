NAME			=	Forms

CXX				=	c++
CXXFLAGS		=	-Wall -Wextra -Werror
CXXFLAGS		+=	-std=c++98

PRE_OPT			=	-MMD -MP
INCLUDE			=	-I$(INCLUDES_DIR)

SRCS_DIR		=	./srcs
OBJS_DIR		=	./objs
INCLUDES_DIR	=	./inc

SRCS			=	Bureaucrat.cpp \
					AForm.cpp \
					ShrubberyCreationForm.cpp \
					RobotomyRequestForm.cpp \
					PresidentialPardonForm.cpp \
					main.cpp

OBJS			=	$(patsubst %.o, $(OBJS_DIR)/%.o, $(SRCS:.cpp=.o))
DEPS			=	$(OBJS:.o=.d)

RM				=	rm -rf

$(OBJS_DIR)	: % :
	@mkdir -p $@

$(NAME)	: $(OBJS_DIR) $(OBJS)
	$(CXX) $(CXXFLAGS) $(INCLUDE) $(OBJS) -o $@

$(OBJS_DIR)/%.o	:	$(SRCS_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDE) $(PRE_OPT) -o $@ -c $<

.DEFAULT_GOAL	=	all
.PHONY:	all
all:	$(NAME)

# INFO ShrubberyCreationFormで作成されるファイルも削除
.PHONY:	clean
clean:
	$(RM) $(OBJS_DIR)
	$(RM) *_shrubbery

.PHONY:	fclean
fclean:	clean
	$(RM) $(NAME)

.PHONY:	re
re:	fclean all

-include $(DEPS)
