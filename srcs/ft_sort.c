/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoffaux <sgoffaux@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 14:45:52 by sgoffaux          #+#    #+#             */
/*   Updated: 2021/06/09 10:05:42 by sgoffaux         ###   ########.fr       */
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
		while (j < size && !(ft_sorted(f->a->head, f->a->len, 1)
				&& ft_sorted(f->b->head, f->b->len, 0)))
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

int	ft_sorted(t_node *n, size_t len, int ascending)
{
	t_node	*tmp;

	tmp = n;
	while (--len)
	{
		if ((tmp->val > tmp->next->val && ascending)
			|| (tmp->val < tmp->next->val && !ascending))
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	ft_sorted_offset(t_frame *f)
{
	size_t	i;
	t_node	*tmp;

	tmp = f->a->head;
	i = 0;
	while (i < f->a->len)
	{
		if (ft_sorted(tmp, f->a->len, 1))
			break ;
		tmp = tmp->next;
		i++;
	}
	if (i <= f->a->len)
	{
		if (i > (f->a->len / 2))
		{
			i = f->a->len - i;
			while (i--)
				ft_rra(f);
		}
		else
			while (i--)
				ft_ra(f);
	}
}

void	ft_rotate(t_frame *f, int target, int max)
{
	size_t	i;
	t_node	*tmp;

	tmp = f->a->head;
	i = 0;
	while (i < f->a->len)
	{
		if (tmp->val == target + 1 || (target == max && tmp->val == 0)
			|| (target > tmp->prev->val && target < tmp->val))
			break ;
		tmp = tmp->next;
		i++;
	}
	if (i <= f->a->len)
	{
		if (i > (f->a->len / 2))
		{
			i = f->a->len - i;
			while (i--)
				ft_rra(f);
		}
		else
			while (i--)
				ft_ra(f);
	}
}
