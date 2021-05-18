/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoffaux <sgoffaux@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 12:26:05 by sgoffaux          #+#    #+#             */
/*   Updated: 2021/05/18 12:36:40 by sgoffaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rx(t_stack *s, char *to_print)
{
	s->head = s->head->prev;
	if (to_print)
		write(1, to_print, 3);
}

void	ft_rr(t_stack *a, t_stack *b, int to_print)
{
	a->head = a->head->prev;
	b->head = b->head->prev;
	if (to_print)
		write(1, "rr\n", 3);
}

void	ft_rrx(t_stack *s, char *to_print)
{
	s->head = s->head->next;
	if (to_print)
		write(1, to_print, 4);
}

void	ft_rrr(t_stack *a, t_stack *b, int to_print)
{
	a->head = a->head->next;
	b->head = b->head->next;
	if (to_print)
		write(1, "rrr\n", 4);
}