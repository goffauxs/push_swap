/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoffaux <sgoffaux@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 10:20:55 by sgoffaux          #+#    #+#             */
/*   Updated: 2021/05/18 14:37:45 by sgoffaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stddef.h>
# include "../libft/libft.h"

typedef struct	s_node
{
	struct s_node	*prev;
	struct s_node	*next;
	int				val;
}				t_node;

typedef struct	s_stack
{
	t_node *head;
	size_t	len;
}				t_stack;

typedef struct	s_frame
{
	t_stack	*a;
	t_stack *b;
}				t_frame;

t_node	*ft_create_node(int num, int first_node);
void	ft_insert_before_head(t_node *head, t_node *node);
void	ft_insert_after_head(t_node *head, t_node *node);
int		ft_get_midpoint(t_node *head, size_t len);
t_node	*ft_free_node(t_node *node);
void	ft_print_dll(t_node *head);
void	ft_sa(t_stack *a, int print);
void	ft_sb(t_stack *b, int print);
void	ft_ss(t_stack *a, t_stack *b, int print);
void	ft_ra(t_stack *a, int print);
void	ft_rb(t_stack *b, int print);
void	ft_rr(t_stack *a, t_stack *b, int print);
void	ft_rra(t_stack *a, int print);
void	ft_rrb(t_stack *b, int print);
void	ft_rrr(t_stack *a, t_stack *b, int print);
void	ft_pa(t_stack *a, t_stack *b, int print);
void	ft_pb(t_stack *a, t_stack *b, int print);

#endif