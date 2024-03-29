/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoffaux <sgoffaux@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 11:29:57 by sgoffaux          #+#    #+#             */
/*   Updated: 2021/07/14 13:52:02 by sgoffaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_frame *f)
{
	int	tmp;

	if (!f->a->head)
		return ;
	if (f->a->head->next)
	{
		tmp = f->a->head->val;
		f->a->head->val = f->a->head->next->val;
		f->a->head->next->val = tmp;
		if (f->print)
			ft_putendl_fd("sa", STDOUT_FILENO);
	}
}

void	ft_sb(t_frame *f)
{
	int	tmp;

	if (!f->b->head)
		return ;
	if (f->b->head->next)
	{
		tmp = f->b->head->val;
		f->b->head->val = f->b->head->next->val;
		f->b->head->next->val = tmp;
		if (f->print)
			ft_putendl_fd("sb", STDOUT_FILENO);
	}
}

void	ft_ss(t_frame *f)
{
	int	tmp;

	if (!f->a->head || !f->b->head)
		return ;
	if (f->a->head->next && f->b->head->next)
	{
		tmp = f->a->head->val;
		f->a->head->val = f->a->head->next->val;
		f->a->head->next->val = tmp;
		tmp = f->b->head->val;
		f->b->head->val = f->b->head->next->val;
		f->b->head->next->val = tmp;
		if (f->print)
			ft_putendl_fd("ss", STDOUT_FILENO);
	}
}
