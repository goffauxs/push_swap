/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoffaux <sgoffaux@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 11:57:50 by sgoffaux          #+#    #+#             */
/*   Updated: 2021/06/08 12:22:25 by sgoffaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_max(t_node *n)
{
	int	max;

	max = n->val;
	if (n->next->val > max)
		max = n->next->val;
	if (n->prev->val > max)
		max = n->prev->val;
	return (max);
}

static int	ft_min(t_node *n)
{
	int	min;

	min = n->val;
	if (n->next->val < min)
		min = n->next->val;
	if (n->prev->val < min)
		min = n->prev->val;
	return (min);
}

static int	ft_mid(t_node *n, int min, int max)
{
	if (n->val != min && n->val != max)
		return (n->val);
	if (n->next->val != min && n->next->val != max)
		return (n->next->val);
	return (n->prev->val);
}

static void	ft_sort_3(t_frame *f, int min, int mid, int max)
{
	if (f->a->head->val == min && f->a->head->next->val == max)
	{
		ft_sa(f);
		ft_ra(f);
	}
	else if (f->a->head->val == mid)
	{
		if (f->a->head->next->val == min)
			ft_sa(f);
		else if (f->a->head->next->val == max)
			ft_rra(f);
	}
	else if (f->a->head->val == max)
	{
		if (f->a->head->next->val == mid)
		{
			ft_sa(f);
			ft_rra(f);
		}
		else
			ft_ra(f);
	}
}

void	ft_solve3(t_frame *f)
{
	int	min;
	int	mid;
	int	max;

	min = ft_min(f->a->head);
	max = ft_max(f->a->head);
	mid = ft_mid(f->a->head, min, max);
	ft_sort_3(f, min, mid, max);
}