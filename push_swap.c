/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoffaux <sgoffaux@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 11:31:06 by sgoffaux          #+#    #+#             */
/*   Updated: 2021/05/18 15:53:56 by sgoffaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
	t_stack a;
	t_stack b;

	if (argc >= 2)
	{
		b.head = NULL;
		b.len = 0;
		a.head = ft_create_node(ft_atoi(argv[1]), 1);
		a.len = 1;
		while (--argc > 1)
		{
			ft_insert_after_head(a.head, ft_create_node(ft_atoi(argv[argc]), 0));
			a.len++;
		}
		printf("A: \n");
		ft_print_dll(a.head);
		printf("\nB: \n");
		ft_print_dll(b.head);
		//pb pb ra ra pb pb rra pb rra pb sb pa pa rb pa pa pa pa
		ft_pb(&a, &b, 1);
		ft_pb(&a, &b, 1);
		ft_ra(&a, 1);
		ft_ra(&a, 1);
		ft_pb(&a, &b, 1);
		ft_pb(&a, &b, 1);
		ft_rra(&a, 1);
		ft_pb(&a, &b, 1);
		ft_rra(&a, 1);
		ft_pb(&a, &b, 1);
		ft_sb(&b, 1);
		ft_pa(&a, &b, 1);
		ft_pa(&a, &b, 1);
		ft_rb(&b, 1);
		ft_pa(&a, &b, 1);
		ft_pa(&a, &b, 1);
		ft_pa(&a, &b, 1);
		ft_pa(&a, &b, 1);
		printf("A: \n");
		ft_print_dll(a.head);
		printf("\nB: \n");
		ft_print_dll(b.head);
	}
}