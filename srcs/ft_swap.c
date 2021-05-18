/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoffaux <sgoffaux@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 11:29:57 by sgoffaux          #+#    #+#             */
/*   Updated: 2021/05/18 15:57:34 by sgoffaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_stack *a, int print)
{
	int	tmp;

	if (!a)
		return ;
	tmp = a->head->val;
	if (a->head->next)
	{
		a->head->val = a->head->next->val;
		a->head->next->val = tmp;
		if (print)
			write(1, "sa\n", 3);
	}
}

void	ft_sb(t_stack *b, int print)
{
	int	tmp;

	if (!b)
		return ;
	tmp = b->head->val;
	if (b->head->next)
	{
		b->head->val = b->head->next->val;
		b->head->next->val = tmp;
		if (print)
			write(1, "sb\n", 3);
	}
}

void	ft_ss(t_stack *a, t_stack *b, int to_print)
{
	int	tmp;

	tmp = a->head->val;
	a->head->val = a->head->next->val;
	a->head->next->val = tmp;
	tmp = b->head->val;
	b->head->val = b->head->next->val;
	b->head->next->val = tmp;
	if (to_print)
		write(1, "ss\n", 1);
}