/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoffaux <sgoffaux@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 12:36:55 by sgoffaux          #+#    #+#             */
/*   Updated: 2021/07/14 13:31:43 by sgoffaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pa(t_frame *f)
{
	int	tmp;

	if (f->b->head)
	{
		tmp = f->b->head->val;
		f->b->head = ft_free_node(f->b->head);
		if (!f->a->head)
			f->a->head = ft_create_node(tmp);
		else
			ft_insert_before(f->a->head, ft_create_node(tmp));
		f->a->head = f->a->head->prev;
		f->b->len--;
		f->a->len++;
		if (f->print)
			write(STDOUT_FILENO, "pa\n", 3);
	}
}

void	ft_pb(t_frame *f)
{
	int	tmp;

	if (f->a->head)
	{
		tmp = f->a->head->val;
		f->a->head = ft_free_node(f->a->head);
		if (!f->b->head)
			f->b->head = ft_create_node(tmp);
		else
			ft_insert_before(f->b->head, ft_create_node(tmp));
		f->b->head = f->b->head->prev;
		f->a->len--;
		f->b->len++;
		if (f->print)
			write(STDOUT_FILENO, "pb\n", 3);
	}
}
