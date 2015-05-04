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
				_status.c

SRCS		=	$(SRCS_LIST:%.c=$(DIR_SRCS)/$(NAME)%.c)

OBJS		=	$(SRCS:.c=.o)

DIR_INC		=	./inc

INC			=	$(DIR_INC)/$(NAME).h

RM			=	rm -fr

CFLAGS		+=	-W -Wall -Wextra -Werror -I$(DIR_INC)

DEBUG		=	-g

CC			=	gcc

LIB			=	ar rc

RANLIB		=	ranlib

$(NAME):	$(NAME_LIB)

$(NAME_LIB):	$(OBJS)
				$(LIB) $(NAME_LIB) $(SRCS) $(INC)
				$(RANLIB) $(NAME_LIB)

all:	$(NAME)

clean:
		$(RM) $(OBJS)

fclean:	clean
		$(RM) $(NAME_LIB)

re:	fclean all
