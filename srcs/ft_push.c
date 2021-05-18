/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoffaux <sgoffaux@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 12:36:55 by sgoffaux          #+#    #+#             */
/*   Updated: 2021/05/18 16:00:29 by sgoffaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pa(t_stack *a, t_stack *b, int print)
{
	int	tmp;
	
	if (b->head)
	{
		tmp = b->head->val;
		b->head = ft_free_node(b->head);
		if (!a->head)
			a->head = ft_create_node(tmp, 1);
		else
			ft_insert_before_head(a->head, ft_create_node(tmp, 0));
		a->head = a->head->prev;
		b->len--;
		a->len++;
		if (print)
			write(1, "pa\n", 3);
	}
}

void	ft_pb(t_stack *a, t_stack *b, int print)
{
	int	tmp;
	
	if (a->head)
	{
		tmp = a->head->val;
		a->head = ft_free_node(a->head);
		if (!b->head)
			b->head = ft_create_node(tmp, 1);
		else
			ft_insert_before_head(b->head, ft_create_node(tmp, 0));
		b->head = b->head->prev;
		a->len--;
		b->len++;
		if (print)
			write(1, "pb\n", 3);
	}
}