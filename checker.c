/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoffaux <sgoffaux@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 10:13:15 by sgoffaux          #+#    #+#             */
/*   Updated: 2021/06/11 16:09:03 by sgoffaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_init_funcs(t_ops *opps)
{
	opps[0].cmd = "sa";
	opps[0].func = &ft_sa;
	opps[1].cmd = "sb";
	opps[1].func = &ft_sb;
	opps[2].cmd = "ss";
	opps[2].func = &ft_ss;
	opps[3].cmd = "pa";
	opps[3].func = &ft_pa;
	opps[4].cmd = "pb";
	opps[4].func = &ft_pb;
	opps[5].cmd = "ra";
	opps[5].func = &ft_ra;
	opps[6].cmd = "rb";
	opps[6].func = &ft_rb;
	opps[7].cmd = "rr";
	opps[7].func = &ft_rr;
	opps[8].cmd = "rra";
	opps[8].func = &ft_rra;
	opps[9].cmd = "rrb";
	opps[9].func = &ft_rrb;
	opps[10].cmd = "rrr";
	opps[10].func = &ft_rrr;
}

static int	ft_check_valid(t_frame *f, t_ops *opps)
{
	int			i;
	int			ret;
	char		*line;

	if (ft_check_duplicate(f->a->head, f->a->len))
	{
		ret = 1;
		while (ret && ret != -1)
		{
			i = 0;
			ret = get_next_line(0, &line);
			if (ret == 0)
				break ;
			while (ft_strncmp(line, opps[i].cmd, ft_strlen(line)))
				i++;
			if (i < 11)
				opps[i].func(f);
		}
	}
	else
	{
		write(1, "Error\n", 6);
		return (0);
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	t_frame	f;
	t_ops	opps[11];

	ft_init_funcs(opps);
	if (ft_treat_errors(argc, argv))
	{
		if (ft_fill_stack(&f, argc, argv))
		{
			f.print = 0;
			if (ft_check_valid(&f, opps))
			{
				if (ft_sorted(f.a->head, f.a->len, 1))
					write(1, "OK\n", 3);
				else
					write(1, "KO\n", 3);
			}
		}
	}
	else
		write(2, "Error\n", 6);
	return (0);
}
