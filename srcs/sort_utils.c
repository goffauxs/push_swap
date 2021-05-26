/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoffaux <sgoffaux@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 11:12:13 by sgoffaux          #+#    #+#             */
/*   Updated: 2021/05/26 12:13:48 by sgoffaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int		ft_get_direction(t_frame *f, int midpoint)
{
	int	i;
	t_node *node_front;
	t_node *node_back;

	i = 1;
	node_front = f->a->head->next;
	node_back = f->a->head->prev;
	while (node_front->val >= midpoint && node_back->val >= midpoint)
	{
		i++;
		if (node_front == f->a->head || node_back == f->a->head)
			return (0);
		node_front = node_front->next;
		node_back = node_back->prev;
	}
	if (node_front->val < midpoint)
		return (i);
	return (-i);
}

int		ft_sorted(t_node *n, size_t len, int ascending)
{
	t_node	*tmp;
	
	tmp = n;
	while (--len)
	{
		if ((ascending && tmp->val > tmp->next->val)
			|| (!ascending && tmp->val < tmp->next->val))
			return (0);
		tmp = tmp->next;
	}
	return (1);
}