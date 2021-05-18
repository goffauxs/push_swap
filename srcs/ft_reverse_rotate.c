/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoffaux <sgoffaux@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 14:14:06 by sgoffaux          #+#    #+#             */
/*   Updated: 2021/05/18 14:17:26 by sgoffaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra(t_stack *a, int print)
{
	if (!a->head)
		return ;
	if (a->head->prev)
		a->head = a->head->prev;
	if (print)
		write(1, "rra\n", 4);
}

void	ft_rrb(t_stack *b, int print)
{
	if (!b->head)
		return ;
	if (b->head->prev)
		b->head = b->head->prev;
	if (print)
		write(1, "rra\n", 4);
}

void	ft_rrr(t_stack *a, t_stack *b, int to_print)
{
	ft_rra(a, 0);
	ft_rrb(b, 0);
	if (to_print)
		write(1, "rrr\n", 4);
}