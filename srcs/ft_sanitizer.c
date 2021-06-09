/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sanitizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoffaux <sgoffaux@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 10:16:17 by sgoffaux          #+#    #+#             */
/*   Updated: 2021/06/09 10:21:20 by sgoffaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_init_frame(t_frame *f)
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

int	ft_check_duplicate(t_node *n, size_t len)
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

int	ft_treat_errors(int argc, char *argv[])
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
