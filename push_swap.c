/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoffaux <sgoffaux@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 11:31:06 by sgoffaux          #+#    #+#             */
/*   Updated: 2021/05/26 16:50:49 by sgoffaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static void	ft_init_stack(t_stack *s, int argc)
{
	size_t	*chunks;

	s->chunk_count = 0;
	while (argc > 1)
	{
		s->chunk_count++;
		argc /= 2;
	}
	chunks = malloc(sizeof(size_t) * s->chunk_count);
	if (!chunks)
		return ;
	s->chunks = chunks;
	s->head = NULL;
	s->len = 0;
}

static void	ft_init_frame(t_frame *f, int argc)
{
	f->a = malloc(sizeof(t_stack *));
	if (!f->a)
		return ;
	f->b = malloc(sizeof(t_stack *));
	if (!f->b)
		return ;
	ft_init_stack(f->a, 0);
	ft_init_stack(f->b, argc);
	f->print = 0;
}

int main(int argc, char *argv[])
{
	t_frame f;

	if (argc >= 2)
	{
		ft_init_frame(&f, argc - 1);
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
		ft_sort_first_pb(&f, 0, 0);
		if (f.a->head->val > f.a->head->next->val)
			ft_sa(&f);
		// ft_sort_pa(&f, 0, chunks, chunk_count - 1);

		// for (int i=f.a->chunk_count; i > 0; i--)
		// 	printf("chunks[%d]: %zu\n", i - 1, f.b->chunks[i - 1]);

		printf("\nA: \n");
		ft_print_dll(f.a->head);
		printf("\nB: \n");
		ft_print_dll(f.b->head);
		
	}
	//system("leaks a.out");
}