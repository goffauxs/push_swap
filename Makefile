# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgoffaux <sgoffaux@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/07 14:59:23 by sgoffaux          #+#    #+#              #
#    Updated: 2021/06/10 13:21:36 by sgoffaux         ###   ########.fr        #
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

LIBFT		=	libft/
GNL			=	get_next_line/

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
				srcs/ft_markup.c

C_SRCS		=	checker.c

S_OBJS		=	$(S_SRCS:.c=.o)
P_OBJS		=	$(P_SRCS:.c=.o)
C_OBJS		=	$(C_SRCS:.c=.o)
OBJS		=	$(S_OBJS) $(P_OBJS) $(C_OBJS)

all:			$(NAME)

$(PUSH_SWAP):	$(S_OBJS) $(P_OBJS) $(LIBFT_A)
				@$(CC) $(CFLAGS) -L. -lft $(S_OBJS) $(P_OBJS) -o push_swap
				@echo "Linked into executable \033[0;32mpush_swap\033[0m."

$(CHECKER):		$(S_OBJS) $(C_OBJS) $(LIBFT_A) $(GNL_A)
				@$(CC) $(CFLAGS) -L. -lft -lgnl $(S_OBJS) $(C_OBJS) -o checker
				@echo "Linked into executable \033[0;32mchecker\033[0m."

$(LIBFT_A):	
				@$(MAKE) -s -C $(LIBFT)
				@echo "Compiled libft.a."
				@cp -p $(addprefix $(LIBFT), $(LIBFT_A)) $(LIBFT_A)

$(GNL_A):	
				@$(MAKE) -s -C $(GNL)
				@echo "Compiled libgnl.a."
				@cp -p $(addprefix $(GNL), $(GNL_A)) $(GNL_A)

.c.o:
				@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)
				@echo "Compiling $<."

localclean:
				@$(RM) $(OBJS)
				@echo "Removed object files."

clean:			localclean
				@$(MAKE) clean -s -C $(LIBFT)
				@echo "Clean libft."
				@$(MAKE) clean -s -C$(GNL)
				@echo "Clean gnl."

fclean:			localclean
				@$(MAKE) fclean -s -C $(LIBFT)
				@echo "Full clean libft."
				@$(MAKE) fclean -s -C $(GNL)
				@echo "Full clean gnl."
				@$(RM) $(LIBFT_A)
				@$(RM) $(GNL_A)
				@echo "Removed libs."
				@$(RM) $(NAME)
				@echo "Removed executables."

re:				fclean all

.PHONY:			all clean fclean re