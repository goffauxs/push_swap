/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoffaux <sgoffaux@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 10:20:33 by sgoffaux          #+#    #+#             */
/*   Updated: 2021/05/14 13:03:20 by sgoffaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long long	ft_get_min(t_stack *a)
{
	long long	min;
	
	min = a->num;
	if (a->next->num < min)
		min = a->next->num;
	if (a->prev->num < min)
		min = a->prev->num;
	return (min);
}

static long long	ft_get_max(t_stack *a)
{
	long long	max;
	
	max = a->num;
	if (a->next->num > max)
		max = a->next->num;
	if (a->prev->num > max)
		max = a->prev->num;
	return (max);
}

static long long	ft_get_mid(t_stack *a, long long min, long long	max)
{
	if (a->num != min && a->num != max)
		return (a->num);
	else if (a->next->num != min && a->next->num != max)
		return (a->next->num);
	else
		return (a->prev->num);
}

static void	ft_solve_3(t_stack *a, long long min, long long mid, long long max)
{
	if (a == min && a->next == max)
	{
			ft_sa(a);
			ft_solve_3(a);
	}
	else if (a == mid)
	{
		if (a->next == min)
			ft_sa(a);
		else
			ft_rra(a);
	}
	else
	{
		ft_ra(a);
		if (a->next == mid)
			ft_solve_3(a);
	}
}

void	solve_3(t_stack *a, int rotate_both)