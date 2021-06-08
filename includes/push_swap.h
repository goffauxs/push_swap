/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoffaux <sgoffaux@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 10:20:55 by sgoffaux          #+#    #+#             */
/*   Updated: 2021/06/08 16:37:57 by sgoffaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stddef.h>
# include "../libft/libft.h"

typedef struct s_node
{
	struct s_node	*prev;
	struct s_node	*next;
	int				val;
}				t_node;

typedef struct s_stack
{
	t_node	*head;
	size_t	len;
}				t_stack;

typedef struct s_frame
{
	t_stack	*a;
	t_stack	*b;
	int		print;
}				t_frame;

t_node	*ft_create_node(int num);
void	ft_insert_after(t_node *head, t_node *node);
void	ft_insert_before(t_node *head, t_node *node);
t_node	*ft_free_node(t_node *node);
void	ft_print_dll(t_node *head);
void	ft_sa(t_frame *f);
void	ft_sb(t_frame *f);
void	ft_ss(t_frame *f);
void	ft_ra(t_frame *f);
void	ft_rb(t_frame *f);
void	ft_rr(t_frame *f);
void	ft_rra(t_frame *f);
void	ft_rrb(t_frame *f);
void	ft_rrr(t_frame *f);
void	ft_pa(t_frame *f);
void	ft_pb(t_frame *f);
void	ft_quicksort_stack(t_stack *a);
void	ft_radix_sort(t_frame *f, size_t size, size_t max_num, size_t max_bits);
void	ft_solve3(t_frame *f);
void	ft_solve5(t_frame *f);
int		ft_sorted(t_node *n, size_t len, int ascending);
void	ft_sorted_offset(t_frame *f);
void	ft_rotate(t_frame *f, int target, int max);

#endif