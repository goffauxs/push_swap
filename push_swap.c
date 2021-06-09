/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoffaux <sgoffaux@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 11:31:06 by sgoffaux          #+#    #+#             */
/*   Updated: 2021/06/09 10:24:32 by sgoffaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_treat_valid(t_frame *f, int argc, char *argv[])
{
	ft_init_frame(f);
	f->a->head = ft_create_node(ft_atoi(argv[1]));
	f->a->len = 1;
	while (--argc > 1)
	{
		ft_insert_after(f->a->head, ft_create_node(ft_atoi(argv[argc])));
		f->a->len++;
	}
	if (ft_check_duplicate(f->a->head, f->a->len))
	{
		ft_sorted_offset(f);
		if (!ft_sorted(f->a->head, f->a->len, 1))
		{
			ft_quicksort_stack(f->a);
			if (f->a->len == 3)
				ft_solve3(f);
			else if (f->a->len == 2 && !ft_sorted(f->a->head, 2, 1))
				ft_sa(f);
			else if (f->a->len <= 5)
				ft_solve5(f);
			else
				ft_radix_sort(f, f->a->len, f->a->len - 1, 0);
		}
	}
}

int	main(int argc, char *argv[])
{
	t_frame	f;

	if (ft_treat_errors(argc, argv))
		ft_treat_valid(&f, argc, argv);
	else
		write(1, "Error\n", 6);
	return (0);
}
