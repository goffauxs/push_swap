/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoffaux <sgoffaux@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 14:45:52 by sgoffaux          #+#    #+#             */
/*   Updated: 2021/06/07 15:42:47 by sgoffaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_radix_sort(t_frame *f, size_t size, size_t max_num, size_t max_bits)
{
	size_t	i;
	size_t	j;
	int		num;

	i = 0;
	while ((max_num >> max_bits) != 0)
		++max_bits;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			num = f->a->head->val;
			if ((num >> i) & 1)
				ft_ra(f);
			else
				ft_pb(f);
			j++;
		}
		while (f->b->len != 0)
			ft_pa(f);
		i++;
	}
}

int	ft_sorted(t_node *n, size_t len)
{
	t_node *tmp;

	tmp = n;
	while (--len)
	{
		if (tmp->val > tmp->next->val)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}