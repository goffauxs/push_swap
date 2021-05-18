/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoffaux <sgoffaux@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 11:29:57 by sgoffaux          #+#    #+#             */
/*   Updated: 2021/05/18 12:31:17 by sgoffaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sx(t_stack *s, char *to_print)
{
	int	tmp;

	tmp = s->head->val;
	s->head->val = s->head->next->val;
	s->head->next->val = tmp;
	if (to_print)
		write(1, to_print, 3);
}

void	ft_ss(t_stack *a, t_stack *b, int to_print)
{
	int	tmp;

	tmp = a->head->val;
	a->head->val = a->head->next->val;
	a->head->next->val = tmp;
	tmp = b->head->val;
	b->head->val = b->head->next->val;
	b->head->next->val = tmp;
	if (to_print)
		write(1, "ss\n", 1);
}