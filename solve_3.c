/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoffaux <sgoffaux@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 10:20:33 by sgoffaux          #+#    #+#             */
/*   Updated: 2021/05/17 10:41:57 by sgoffaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long long	ft_get_min(t_list *a)
{
	long long	min;
	
	min = a->content;
	if (a->next->content < min)
		min = a->next->content;
	if (a->prev->content < min)
		min = a->prev->content;
	return (min);
}

static long long	ft_get_max(t_list *a)
{
	long long	max;
	
	max = a->content;
	if (a->next->content > max)
		max = a->next->content;
	if (a->prev->content > max)
		max = a->prev->content;
	return (max);
}

static long long	ft_get_mid(t_list *s, long long min, long long	max)
{
	if (s->content != min && s->content != max)
		return (s->content);
	else if (s->next->content != min && s->next->content != max)
		return (s->next->content);
	else
		return (s->prev->content);
}

static void	ft_solve_3(t_frame *f, long long min, long long mid, long long max)
{
	if (f->a == min && f->a->next == max)
	{
		ft_sa(s);
		ft_solve_3(s, min, mid, max);
	}
	else if (s == mid)
	{
		if (s->next == min)
			ft_sa(s);
		else
			ft_rra(s);
	}
	else
	{
		ft_ra(s);
		if (s->next == mid)
			ft_solve_3(s, min, mid, max);
	}
}

void	solve_3(t_list *s, int rev)
{
	long long	min;
	long long	mid;
	long long	max;

	if (rev)
	{
		min = ft_get_max(s);
		max = ft_get_min(s);
	}
	else
	{
		min = ft_get_min(s);
		max = ft_get_max(s);
	}
	mid = ft_get_mid(s, min, max);
	
}