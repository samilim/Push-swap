#ANSI codes used to add colors on my printf / echos
RED			='\033[0;31m'
PURPLE		='\033[0;35m'
YELLOW		='\033[1;33m'
GREEN		='\033[1;32m'
NONE		='\033[0m'

# comp
NAME		= push_swap
CC			= gcc
CFLAGS		= -Wall -Werror -Wextra
AR 			= ar rcs
RM			= rm -f

# directories
INC_PATH	:= includes
SRCS_PATH	:= srcs
BONUS_PATH	:= bonus

SRCS 		= srcs/push_swap.c \
			srcs/check_error.c \
			srcs/parsing.c \
			srcs/sorting.c \
			srcs/push.c \
			srcs/swap.c \
			srcs/rotate.c \
			srcs/reverse.c \
			srcs/clear.c \
			srcs/stack_management.c \
			srcs/utils.c \
			srcs/algo.c \
			srcs/radix.c \

SRCS_BONUS				= push_swap_bonus.c \
						check_error_bonus.c \

# libft
LIBFT_PATH	:= libft/
LIBFT_LIB	= $(addprefix $(LIBFT_PATH),libft.a)
LIBFT_INC	= -I ./libft
LIBFT_LNK	= -L ./libft -l ft -l pthread

OBJS		= $(SRCS:.c=.o)
OBJS_BONUS	= $(SRCS_BONUS:.c=.o)

all:		$(LIBFT_LIB) $(NAME)

%.o: %.c	$(SRCS_PATH)/%.c
			$(CC) $(CFLAGS) $(LIBFT_INC) -I $(INC_PATH) -o $@ -c $<

$(LIBFT_LIB):
	@make -C $(LIBFT_PATH)

$(NAME):	$(OBJS)
			$(CC) $(OBJS) $(LIBFT_LNK) -o $(NAME)
			@echo -e ${GREEN}You can enter the parameter in two different manners \; one unique str that contain all numbers \"nb1 nb2 nb3\", or directly enter each number as agument, like stated in the new subject.${NONE}

bonus:		$(LIBFT_LIB) $(OBJS_BONUS)
			$(CC) $(OBJS_BONUS) $(LIBFT_LNK) -o $(NAME)

clean:
			$(RM) $(OBJS) $(OBJS_BONUS)
			make -C $(LIBFT_PATH) clean

fclean:		clean
			$(RM) $(NAME)
			make -C $(LIBFT_PATH) fclean

re:			fclean all

.PHONY:		all re clean fclean bonus