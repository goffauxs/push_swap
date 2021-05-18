/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoffaux <sgoffaux@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 12:26:05 by sgoffaux          #+#    #+#             */
/*   Updated: 2021/05/18 14:13:49 by sgoffaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_stack *a, int print)
{
	if (!a->head)
		return ;
	if (a->head->next)
		a->head = a->head->next;
	if (print)
		write(1, "sa\n", 3);
}

void	ft_rb(t_stack *b, int print)
{
	if (!b->head)
		return ;
	if (b->head->next)
		b->head = b->head->next;
	if (print)
		write(1, "sb\n", 3);
}

void	ft_rr(t_stack *a, t_stack *b, int print)
{
	ft_ra(a, 0);
	ft_rb(b, 0);
	if (print)
		write(1, "rr\n", 3);
}