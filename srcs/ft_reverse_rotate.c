/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoffaux <sgoffaux@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 14:14:06 by sgoffaux          #+#    #+#             */
/*   Updated: 2021/05/19 10:13:31 by sgoffaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra(t_frame *f)
{
	if (!f->a->head)
		return ;
	if (f->a->head->prev)
		f->a->head = f->a->head->prev;
	if (f->print)
		write(1, "rra\n", 4);
}

void	ft_rrb(t_frame *f)
{
	if (!f->b->head)
		return ;
	if (f->b->head->prev)
		f->b->head = f->b->head->prev;
	if (f->print)
		write(1, "rra\n", 4);
}

void	ft_rrr(t_frame *f)
{
	if (!f->a->head || !f->b->head)
		return ;
	if (f->a->head->prev)
		f->a->head = f->a->head->prev;
	if (f->b->head->prev)
		f->b->head = f->b->head->prev;
	if (f->print)
		write(1, "rrr\n", 4);
}