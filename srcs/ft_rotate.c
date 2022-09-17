/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoffaux <sgoffaux@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 12:26:05 by sgoffaux          #+#    #+#             */
/*   Updated: 2021/07/14 13:51:49 by sgoffaux         ###   ########.fr       */
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
		ft_putendl_fd("ra", STDOUT_FILENO);
}

void	ft_rb(t_frame *f)
{
	if (!f->b->head)
		return ;
	if (f->b->head->next)
		f->b->head = f->b->head->next;
	if (f->print)
		ft_putendl_fd("rb", STDOUT_FILENO);
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
		ft_putendl_fd("rr", STDOUT_FILENO);
}
