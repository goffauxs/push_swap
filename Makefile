# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgoffaux <sgoffaux@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/07 14:59:23 by sgoffaux          #+#    #+#              #
#    Updated: 2021/07/26 16:29:04 by sgoffaux         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PUSH_SWAP	=	push_swap
CHECKER		=	checker
NAME		=	$(PUSH_SWAP) $(CHECKER)
LIBFT_A		=	libft.a
GNL_A		=	libgnl.a

CC			=	gcc
INCLUDE 	=	includes
CFLAGS		=	-Wall -Wextra -Werror -I$(INCLUDE)
RM			=	rm -f

LIBFT_DIR	=	libft/
GNL_DIR		=	get_next_line/

LIBFT		=	$(addprefix $(LIBFT_DIR), $(LIBFT_A))
GNL			=	$(addprefix $(GNL_DIR), $(GNL_A))

S_SRCS		=	srcs/ft_dll.c \
				srcs/ft_push.c \
				srcs/ft_reverse_rotate.c \
				srcs/ft_rotate.c \
				srcs/ft_sort.c \
				srcs/ft_swap.c \
				srcs/ft_sanitizer.c \

P_SRCS		=	push_swap.c \
				srcs/ft_quicksort.c \
				srcs/ft_solve_3.c \
				srcs/ft_solve_5.c \

C_SRCS		=	checker.c

S_OBJS		=	$(S_SRCS:%.c=%.o)
P_OBJS		=	$(P_SRCS:%.c=%.o)
C_OBJS		=	$(C_SRCS:%.c=%.o)
OBJS		=	$(S_OBJS) $(P_OBJS) $(C_OBJS)

all:			$(NAME)

$(PUSH_SWAP):	$(S_OBJS) $(P_OBJS) $(LIBFT)
				@$(CC) $(CFLAGS) $(S_OBJS) $(P_OBJS) -L$(LIBFT_DIR) -lft -o push_swap
				@echo "Linked into executable \033[0;32mpush_swap\033[0m."

$(CHECKER):		$(S_OBJS) $(C_OBJS) $(LIBFT) $(GNL)
				@$(CC) $(CFLAGS) $(S_OBJS) $(C_OBJS) -L$(LIBFT_DIR) -lft -L$(GNL_DIR) -lgnl -o checker
				@echo "Linked into executable \033[0;32mchecker\033[0m."

$(LIBFT):
				@$(MAKE) -s -C $(LIBFT_DIR)
				@echo "Compiled libft.a."

$(GNL):
				@$(MAKE) -s -C $(GNL_DIR)
				@echo "Compiled libgnl.a."

.c.o:
				@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)
				@echo "Compiling $<."

localclean:
				@$(RM) $(OBJS)
				@echo "Removed object files."

clean:			localclean
				@$(MAKE) clean -s -C $(LIBFT_DIR)
				@echo "Clean libft."
				@$(MAKE) clean -s -C$(GNL_DIR)
				@echo "Clean gnl."

fclean:			localclean
				@$(MAKE) fclean -s -C $(LIBFT_DIR)
				@echo "Full clean libft."
				@$(MAKE) fclean -s -C $(GNL_DIR)
				@echo "Full clean gnl."
				@$(RM) $(NAME)
				@echo "Removed executables."

re:				fclean all

.PHONY:			all clean fclean re