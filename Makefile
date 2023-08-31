# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvalerio <mvalerio@student.42lisboa.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/31 17:22:06 by mvalerio          #+#    #+#              #
#    Updated: 2023/08/31 19:09:03 by mvalerio         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

LIB = libft/libft.a

SRC = algorithm.c data.c data2.c data3.c lists.c protections.c protections2.c \
	reverse_rotate_checker.c reverse_rotate.c rotate_checker.c \
	rotate.c swap_and_push_checker.c swap_and_push.c tests.c utils.c utils2.c \
	utils3.c

PUSHSWAP = push_swap.c

BONUS = checker.c

OBJS = $(SRC:.c=.o)

%.o: %.c
	@$(CC) $(CFLAGS) -c -o $@ $<

all: $(NAME)

$(NAME): $(OBJS)
	@make -s -C libft
	@make -s bonus -C libft
	@$(CC) $(CFLAGS) -o $(NAME) $(PUSHSWAP) $(OBJS) $(LIB)
	@echo "Object files created. Push_swap is now ready to run!"

clean:
	@rm -rf $(OBJS) $(PUSHSWAP:.c=.o) $(BONUS:.c=.o)
	@make -s clean -C libft
	@echo "Your object files were deleted."

fclean: clean
	@rm -rf $(NAME) checker
	@make -s fclean -C libft
	@echo "Your programs were deleted."

re: fclean all

bonus: re
	@$(CC) $(CFLAGS) -o checker $(BONUS) $(OBJS) $(LIB)
	@echo "Your checker is ready to run. You must run the checker with the \
	same arguments, and use the output of push_swap as an input to \
	check if it is correct."
