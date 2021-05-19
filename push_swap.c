/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoffaux <sgoffaux@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 11:31:06 by sgoffaux          #+#    #+#             */
/*   Updated: 2021/05/19 15:15:43 by sgoffaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static void	ft_init_stack(t_stack *s)
{
	s->head = NULL;
	s->len = 0;
}

static void	ft_init_frame(t_frame *f)
{
	f->a = malloc(sizeof(t_stack *));
	if (!f->a)
		return ;
	f->b = malloc(sizeof(t_stack *));
	if (!f->b)
		return ;
	ft_init_stack(f->a);
	ft_init_stack(f->b);
	f->print = 0;
}

int main(int argc, char *argv[])
{
	t_frame f;

	if (argc >= 2)
	{
		ft_init_frame(&f);
		f.b->head = NULL;
		f.b->len = 0;
		f.a->head = ft_create_node(ft_atoi(argv[1]));
		f.a->len = 1;
		f.print = 1;
		while (--argc > 1)
		{
			ft_insert_after_head(f.a->head, ft_create_node(ft_atoi(argv[argc])));
			f.a->len++;
		}
		printf("A: \n");
		ft_print_dll(f.a->head);
		printf("\nB: \n\n");
		ft_print_dll(f.b->head);
		//printf("%d\n", ft_get_midpoint(f.a->head, f.a->len));
		ft_sort_pb(&f, 0, 0);
		//ft_sort_pa(&f);
		printf("\nA: \n");
		ft_print_dll(f.a->head);
		printf("\nB: \n");
		ft_print_dll(f.b->head);
	}
	//system("leaks a.out");
}