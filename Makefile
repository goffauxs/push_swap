# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgoffaux <sgoffaux@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/07 14:59:23 by sgoffaux          #+#    #+#              #
#    Updated: 2021/06/08 12:21:26 by sgoffaux         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	push_swap.c \
			srcs/dll.c \
			srcs/ft_push.c \
			srcs/ft_reverse_rotate.c \
			srcs/ft_rotate.c \
			srcs/ft_sort.c \
			srcs/ft_swap.c \
			srcs/quicksort.c \
			srcs/ft_solve_3.c \

OBJS	=	$(SRCS:%.c=%.o)

CC		=	gcc

INCLUDE =	includes

CFLAGS	=	-Wall -Wextra -Werror -I$(INCLUDE)

RM		=	rm -f

NAME	=	push_swap

all:		$(NAME)

$(NAME):	$(OBJS)
			$(MAKE) -C libft
			cp -p libft/libft.a libft.a
			$(CC) $(CFLAGS) -L. -lft $(OBJS) -o $(NAME)

clean:
			$(MAKE) clean -C libft
			$(RM) $(OBJS)

fclean:		clean
			$(MAKE) fclean -C libft
			$(RM) libft.a
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re