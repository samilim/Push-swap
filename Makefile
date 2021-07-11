NAME		= push_swap
CC			= gcc
CFLAGS		= -Wall -Werror -Wextra
AR 			= ar rcs
RM			= rm -f
IFLAGS		= -include push_swap.h

SRCS 		= push_swap.c \
			check_error.c \

SRCS_BONUS				= push_swap_bonus.c \
						check_error_bonus.c \
						checker_bonus.c \

SRCS_PATH	= srcs/
INC_PATH	= includes
OBJS		= $(SRCS:.c=.o)
OBJS_BONUS	= $(SRCS_BONUS:.c=.o)

all:		$(NAME)

%.o:		%.c
			$(CC) $(CFLAGS) $(IFLAGS) -o $@ -c $<

$(NAME):	$(OBJS)
			$(AR) $(NAME) $(OBJS)

bonus:		$(OBJS) $(OBJS_BONUS)
			$(AR) $(NAME) $(OBJS) $(OBJS_BONUS)

clean:
			$(RM) $(OBJS) $(OBJS_BONUS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all re clean fclean