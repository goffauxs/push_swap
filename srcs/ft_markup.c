/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_markup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoffaux <sgoffaux@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 12:25:00 by sgoffaux          #+#    #+#             */
/*   Updated: 2021/06/10 13:11:09 by sgoffaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_still_no_keep(t_frame *f)
{
	t_node	*tmp;

	tmp = f->a->head->next;
	while (tmp != f->a->head)
	{
		if (!tmp->keep)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	ft_markup_greater(t_node *m_head)
{
	int		cur;
	t_node	*tmp;

	cur = m_head->val;
	tmp = m_head->next;
	while (tmp != m_head)
	{
		if (tmp->val > cur)
		{
			cur = tmp->val;
			tmp->keep = 1;
		}
		tmp = tmp->next;
	}
}

void	ft_markup_index(t_node *m_head)
{
	int		cur;
	t_node	*tmp;

	cur = m_head->val;
	tmp = m_head->next;
	while (tmp != m_head)
	{
		if (tmp->val == cur + 1)
		{
			cur++;
			tmp->keep = 1;
		}
		tmp = tmp->next;
	}
}

void	ft_sort_markup(t_frame *f)
{
	while (ft_still_no_keep(f))
	{
		if (!f->a->head->keep)
			ft_pb(f);
		else
			ft_ra(f);
	}
}