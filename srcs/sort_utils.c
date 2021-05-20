/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoffaux <sgoffaux@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 11:12:13 by sgoffaux          #+#    #+#             */
/*   Updated: 2021/05/20 14:58:35 by sgoffaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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