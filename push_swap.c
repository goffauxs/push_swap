/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoffaux <sgoffaux@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 11:31:06 by sgoffaux          #+#    #+#             */
/*   Updated: 2021/05/18 12:22:04 by sgoffaux         ###   ########.fr       */
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
		ft_print_dll(a.head);
		ft_swap(&a, "sa\n");
		ft_print_dll(a.head);
	}
}