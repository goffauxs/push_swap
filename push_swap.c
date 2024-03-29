/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoffaux <sgoffaux@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 11:31:06 by sgoffaux          #+#    #+#             */
/*   Updated: 2021/07/27 14:15:32 by sgoffaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_treat_valid(t_frame *f)
{
	if (ft_check_duplicate(f->a->head, f->a->len))
	{
		ft_sorted_offset(f);
		if (!ft_sorted(f->a->head, f->a->len, 1))
		{
			ft_quicksort_stack(f->a);
			if (f->a->len == 3)
				ft_solve3(f);
			else if (f->a->len <= 5)
				ft_solve5(f);
			else
				ft_radix_sort(f, f->a->len, f->a->len - 1, 0);
		}
		ft_print(NULL, 0, f);
	}
	else
		ft_print("Error", STDERR_FILENO, f);
}

int	main(int argc, char *argv[])
{
	t_frame	f;

	if (ft_treat_errors(argc, argv))
	{
		if (ft_fill_stack(&f, argc, argv))
			ft_treat_valid(&f);
	}
	else
		ft_print("Error", STDERR_FILENO, &f);
	return (0);
}
