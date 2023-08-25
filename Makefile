# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvalerio <mvalerio@student.42lisboa.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/13 13:46:45 by mvalerio          #+#    #+#              #
#    Updated: 2023/08/23 23:21:57 by mvalerio         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a

SRC = algorithm.c data.c data2.c lists.c protections.c push_swap.c \
      reverse_rotate.c rotate.c swap_and_push.c utils.c utils2.c \
      utils3.c protections2.c data3.c tests.c

LIBFT = libft/ft_atoi.c libft/ft_bzero.c libft/ft_isalnum.c libft/ft_isalpha.c \
	libft/ft_isascii.c libft/ft_isdigit.c libft/ft_isprint.c libft/ft_memchr.c \
	libft/ft_memcmp.c libft/ft_memcpy.c libft/ft_memmove.c libft/ft_memset.c \
	libft/ft_strchr.c libft/ft_strlcat.c libft/ft_strlcpy.c libft/ft_strlen.c \
	libft/ft_strncmp.c libft/ft_strnstr.c libft/ft_strrchr.c libft/ft_tolower.c \
	libft/ft_toupper.c libft/ft_calloc.c libft/ft_strdup.c libft/ft_substr.c \
	libft/ft_strjoin.c libft/ft_strtrim.c libft/ft_split.c libft/ft_itoa.c \
	libft/ft_strmapi.c libft/ft_striteri.c libft/ft_putchar_fd.c libft/ft_putstr_fd.c \
	libft/ft_putendl_fd.c libft/ft_putnbr_fd.c libft/ft_printf.c libft/ft_printed.c \
	libft/ft_lstnew.c libft/ft_lstadd_front.c libft/ft_lstsize.c \
	libft/ft_lstlast.c libft/ft_lstadd_back.c libft/ft_lstdelone.c \
	libft/ft_lstclear.c libft/ft_lstiter.c libft/ft_lstmap.c

BONUS = libft/ft_atoi.c libft/ft_bzero.c libft/ft_isalnum.c libft/ft_isalpha.c \
	libft/ft_isascii.c libft/ft_isdigit.c libft/ft_isprint.c libft/ft_memchr.c \
	libft/ft_memcmp.c libft/ft_memcpy.c libft/ft_memmove.c libft/ft_memset.c \
	libft/ft_strchr.c libft/ft_strlcat.c libft/ft_strlcpy.c libft/ft_strlen.c \
	libft/ft_strncmp.c libft/ft_strnstr.c libft/ft_strrchr.c libft/ft_tolower.c \
	libft/ft_toupper.c libft/ft_calloc.c libft/ft_strdup.c libft/ft_substr.c \
	libft/ft_strjoin.c libft/ft_strtrim.c libft/ft_split.c libft/ft_itoa.c \
	libft/ft_strmapi.c libft/ft_striteri.c libft/ft_putchar_fd.c libft/ft_putstr_fd.c \
	libft/ft_putendl_fd.c libft/ft_putnbr_fd.c libft/ft_printf.c libft/ft_printed.c \
	libft/ft_lstnew.c libft/ft_lstadd_front.c libft/ft_lstsize.c \
	libft/ft_lstlast.c libft/ft_lstadd_back.c libft/ft_lstdelone.c \
	libft/ft_lstclear.c libft/ft_lstiter.c libft/ft_lstmap.c algorithm.c data.c data2.c \
	lists.c protections.c \
	reverse_rotate.c rotate.c swap_and_push.c utils.c utils2.c \
	utils3.c protections2.c data3.c tests.c reverse_rotate_checker.c rotate_checker.c swap_and_push_checker.c checker.c \
	libft/get_next_line/get_next_line.c libft/get_next_line/get_next_line_utils.c

CFLAGS := -Wall -Wextra -Werror

CC = cc -g -c $(CFLAGS)

all: $(NAME)

$(NAME):
	make -C libft
	make bonus -C libft
	$(CC) $(SRC)
	ar rcs $(NAME) $(SRC:.c=.o) $(LIBFT:.c=.o)
	cc -Wall -Wextra -Werror -g push_swap.a -o push_swap

clean:
	rm -f $(SRC:.c=.o)
	make clean -C libft

fclean: clean
	rm -f $(NAME)
	make fclean -C libft
	rm -rf push_swap

re: fclean all

bonus:
	cc -Wall -Wextra -Werror -g $(BONUS) -o checker

