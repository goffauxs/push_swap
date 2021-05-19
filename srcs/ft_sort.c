/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoffaux <sgoffaux@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 14:45:52 by sgoffaux          #+#    #+#             */
/*   Updated: 2021/05/19 15:16:50 by sgoffaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	ft_sort_pb(t_frame *f, int midpoint, int pb_counter)
{
	int	direction;
	
	while (f->a->len > 2)
	{
		if (!pb_counter)
		{
			pb_counter = (f->a->len / 2);
			midpoint = ft_get_midpoint(f->a->head, f->a->len);
			
		}
		while (f->a->head->val < midpoint)
		{
			ft_pb(f);
			pb_counter--;
		}
		direction = ft_get_direction(f, midpoint);
		if (direction < 0)
			while (direction++)
				ft_rra(f);
		else if (direction > 0)
			while (direction--)
				ft_ra(f);
	}
}

void	ft_sort_pa(t_frame *f)
{
	while (f->b->head)
	{
		if (f->b->head->val < f->b->head->next->val)
			ft_sb(f);
		ft_pa(f);
	}
}