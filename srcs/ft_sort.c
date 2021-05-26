/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoffaux <sgoffaux@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 14:45:52 by sgoffaux          #+#    #+#             */
/*   Updated: 2021/05/26 16:42:09 by sgoffaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	ft_sort_first_pb(t_frame *f, int midpoint, size_t pb_counter)
{
	int	direction;
	int	i;
	
	i = 0;
	while (f->a->len > 2)
	{
		if (!pb_counter)
		{
			pb_counter = (f->a->len / 2);
			midpoint = ft_get_midpoint(f->a->head, f->a->len);
			f->b->chunks[i++] = pb_counter;
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

void	ft_sort_pa(t_frame *f, int midpoint, int *chunks, int chunk_count)
{
	int	rb_counter;
	int	pa_counter;

	while (chunk_count >= 0)
	{
		rb_counter = 0;
		pa_counter = 0;
		midpoint = ft_get_midpoint(f->b->head, chunks[chunk_count]);
		while (chunks[chunk_count] > 0)
		{
			if (f->b->head->val >= midpoint)
			{
				ft_pa(f);
				pa_counter++;
				chunks[chunk_count] -= 1;
			}
			else
			{
				ft_rb(f);
				rb_counter++;
			}
		}
		while (rb_counter--)
			ft_rrb(f);
		chunk_count--;
	}
}