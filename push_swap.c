/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoffaux <sgoffaux@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 11:31:06 by sgoffaux          #+#    #+#             */
/*   Updated: 2021/06/08 12:22:45 by sgoffaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_init_frame(t_frame *f)
{
	f->a = malloc(sizeof(t_stack *));
	if (!f->a)
		return ;
	f->b = malloc(sizeof(t_stack *));
	if (!f->b)
		return ;
	f->a->head = NULL;
	f->a->len = 0;
	f->b->head = NULL;
	f->b->len = 0;
	f->print = 1;
}

static int ft_treat_errors(int argc, char *argv[])
{
	int	i;
	if (argc < 2)
		return (0);
	else
	{
		while (argc-- > 1)
		{
			i = 0;
			while (argv[argc][i])
			{
				if (!ft_isdigit(*argv[argc]) && *argv[argc] != '-')
					return (0);
				i++;
			}
			if (!ft_isint(argv[argc]))
				return (0);
		}
	}
	return (1);
}

static int	ft_check_duplicate(t_node *n, size_t len)
{
	t_node	*comp;
	t_node	*tmp;
	size_t	i;
	size_t	j;

	i = 0;
	comp = n;
	tmp = n;
	while (i < len)
	{
		j = 0;
		while (j < len)
		{
			if (comp->val == tmp->val && comp != tmp)
			{
				write(1, "Error\n", 6);
				return (0);
			}
			j++;
			tmp = tmp->next;
		}
		i++;
		comp = comp->next;
	}
	return (1);
}

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
		if (ft_sorted(f->a->head, f->a->len))
			return ;
		else
		{
			if (f->a->len <= 3)
				ft_solve3(f);
			else
			{
				ft_quicksort_stack(f->a);
				ft_radix_sort(f, f->a->len, f->a->len - 1, 0);
			}
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
