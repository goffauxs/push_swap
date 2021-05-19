/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoffaux <sgoffaux@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 12:26:05 by sgoffaux          #+#    #+#             */
/*   Updated: 2021/05/19 15:08:47 by sgoffaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_frame *f)
{
	if (!f->a->head)
		return ;
	if (f->a->head->next)
		f->a->head = f->a->head->next;
	if (f->print)
		write(1, "ra\n", 3);
}

void	ft_rb(t_frame *f)
{
	if (!f->b->head)
		return ;
	if (f->b->head->next)
		f->b->head = f->b->head->next;
	if (f->print)
		write(1, "rb\n", 3);
}

void	ft_rr(t_frame *f)
{
	if (!f->a->head || !f->b->head)
		return ;
	if (f->a->head->next)
		f->a->head = f->a->head->next;
	if (f->b->head->next)
		f->b->head = f->b->head->next;
	if (f->print)
		write(1, "rr\n", 3);
}