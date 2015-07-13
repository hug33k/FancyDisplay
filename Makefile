##
## FancyDisplay
##

NAME		=	FancyDisplay

NAME_LIB	=	libfancydisplay.a

DIR_SRCS	=	./srcs

SRCS_LIST	=	_color.c \
				_config.c \
				_info.c \
				_message.c \
				_status.c \
				_cell.c \
				_table.c

SRCS		=	$(SRCS_LIST:%.c=$(DIR_SRCS)/$(NAME)%.c)

OBJS		=	$(SRCS:.c=.o)

DIR_INC		=	./inc

INC			=	$(DIR_INC)/$(NAME).h

DIR_TEST	=	./tests

DIR_SRCTEST	=	$(DIR_TEST)/srcs

DIR_BINTEST	=	$(DIR_TEST)/bins

TEST		=	$(wildcard $(DIR_SRCTEST)/*.c)

RM			=	rm -fr

CFLAGS		+=	-W -Wall -Wextra -Werror -I$(DIR_INC)

DFLAGS		=	$(CFLAGS) -g

CC			=	gcc

LIB			=	ar rcs

RANLIB		=	ranlib

$(NAME):	$(NAME_LIB)

$(NAME_LIB):	$(OBJS)
				$(LIB) $(NAME_LIB) $(OBJS) $(INC)
				$(RANLIB) $(NAME_LIB)

all:	$(NAME)

%.o:	%.c
		$(CC) $(CFLAGS) -c -o $@ $<

test:	$(NAME)
		$(foreach single_test,$(TEST), $(shell $(CC) $(single_test) $(DFLAGS) -o $(single_test:$(DIR_SRCTEST)/%.c=$(DIR_BINTEST)/%) -L. -l$(NAME_LIB:lib%.a=%)))

clean:
		$(RM) $(OBJS)

fclean:	clean
		$(RM) $(NAME_LIB)

re:	fclean all
