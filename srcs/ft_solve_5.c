/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoffaux <sgoffaux@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 13:25:01 by sgoffaux          #+#    #+#             */
/*   Updated: 2021/06/08 16:23:12 by sgoffaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_solve4(t_frame *f)
{
	ft_pb(f);
	ft_solve3(f);
	ft_rotate(f, f->b->head->val, 3);
	ft_pa(f);
	ft_sorted_offset(f);
}

void	ft_solve5(t_frame *f)
{
	if (f->a->len == 4)
		ft_solve4(f);
	else
	{
		ft_pb(f);
		ft_pb(f);
		ft_solve3(f);
		ft_rotate(f, f->b->head->val, 4);
		ft_pa(f);
		ft_rotate(f, f->b->head->val, 4);
		ft_pa(f);
		ft_sorted_offset(f);
	}
}
