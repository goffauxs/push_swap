/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoffaux <sgoffaux@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 10:13:15 by sgoffaux          #+#    #+#             */
/*   Updated: 2021/07/14 15:47:11 by sgoffaux         ###   ########.fr       */
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
	char		*line;

	if (ft_check_duplicate(f->a->head, f->a->len))
	{
		while (get_next_line(STDIN_FILENO, &line) > 0)
		{
			i = -1;
			while (++i < 11)
				if (ft_strlen(line) == ft_strlen(opps[i].cmd)
					&& !ft_strncmp(line, opps[i].cmd, ft_strlen(opps[i].cmd)))
					break ;
			if (i >= 11)
				return (0);
			if (i < 11)
				opps[i].func(f);
		}
		free(line);
	}
	else
		return (0);
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
					ft_putendl_fd("OK", STDOUT_FILENO);
				else
					ft_putendl_fd("KO", STDOUT_FILENO);
			}
			else
				ft_putendl_fd("Error", STDERR_FILENO);
		}
	}
	else
		ft_putendl_fd("Error", STDERR_FILENO);
	return (0);
}
