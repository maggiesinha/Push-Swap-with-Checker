# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maggie <maggie@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/31 17:22:06 by mvalerio          #+#    #+#              #
#    Updated: 2023/09/05 14:36:28 by maggie           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

LIB = libft/libft.a

SRC = push_swap_files/algorithm.c push_swap_files/data.c \
push_swap_files/data2.c push_swap_files/data3.c push_swap_files/lists.c \
push_swap_files/protections.c push_swap_files/protections2.c \
push_swap_files/reverse_rotate.c push_swap_files/rotate.c \
push_swap_files/swap_and_push.c push_swap_files/tests.c \
push_swap_files/utils.c \
push_swap_files/utils2.c push_swap_files/utils3.c \


SRCBONUS = checker_files/swap_and_push_checker.c checker_files/checker_utils.c \
checker_files/reverse_rotate_checker.c  checker_files/rotate_checker.c \
checker_files/checker_utils2.c

PUSHSWAP = push_swap_files/push_swap_main.c

CHECKER = checker_files/checker_main.c

OBJS = $(SRC:.c=.o)

OBJSBONUS = $(SRCBONUS:.c=.o)

%.o: %.c
	@$(CC) $(CFLAGS) -c -o $@ $<

all: $(NAME)

$(NAME): $(OBJS)
	@make -s -C libft
	@make -s bonus -C libft
	@$(CC) $(CFLAGS) -o $(NAME) $(PUSHSWAP) $(OBJS) $(LIB)
	@echo "Object files created. Push_swap is now ready to run!"

clean:
	@rm -rf $(OBJS) $(OBJSBONUS)
	@make -s clean -C libft
	@echo "Your object files were deleted."

fclean: clean
	@rm -rf $(NAME) checker
	@make -s fclean -C libft
	@echo "Your programs were deleted."

re: fclean all

bonus: re $(OBJSBONUS)
	@$(CC) $(CFLAGS) -o checker $(CHECKER) $(OBJS) $(OBJSBONUS) $(LIB)
	@echo "Your checker is ready to run. You must run the checker with the \
	same arguments, and use the output of push_swap as an input to \
	check if it is correct."
