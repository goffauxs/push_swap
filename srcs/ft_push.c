/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoffaux <sgoffaux@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 12:36:55 by sgoffaux          #+#    #+#             */
/*   Updated: 2021/05/18 12:51:56 by sgoffaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_px(t_stack *a, t_stack *b, char *to_print)
{
	int	tmp;
	
	if (!ft_strncmp(to_print, "pa\n", 3))
	{
		tmp = b->head->val;
		ft_free_node(b->head);
		if (!a->head)
			ft_insert_before_head(a->head, ft_create_node(tmp, 1));
		else
			ft_insert_before_head(a->head, ft_create_node(tmp, 0));
		a->head = a->head->prev;
	}
	else if (!ft_strncmp(to_print, "pb\n", 3))
	{
		tmp = a->head->val;
		ft_free_node(a->head);
		if (!b->head)
			ft_insert_before_head(b->head, ft_create_node(tmp, 1));
		else
			ft_insert_before_head(b->head, ft_create_node(tmp, 0));
		b->head = b->head->prev;
	}
	if (to_print)
		write(1, to_print, 3);
}