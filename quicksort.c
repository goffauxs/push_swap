/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoffaux <sgoffaux@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 11:30:42 by sgoffaux          #+#    #+#             */
/*   Updated: 2021/05/17 16:30:31 by sgoffaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static int	ft_partition(int array[], int low, int high)
{
	int	pivot;
	int	i;
	int	j;
	int	tmp;

	pivot = array[high];
	i = low - 1;
	j = low;
	while (j <= high - 1)
	{
		if (array[j] < pivot)
		{
			i++;
			tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;
		}
		j++;
	}
	tmp = array[i + 1];
	array[i + 1] = array[high];
	array[high] = tmp;
	return (i + 1);
}

void	ft_quicksort_recursive(int array[], int low, int high)
{
	int	pi;

	if (low < high)
	{
		pi = ft_partition(array, low, high);
		ft_quicksort_recursive(array, low, pi - 1);
		ft_quicksort_recursive(array, pi + 1, high);
	}
}

int	ft_create_array(t_stack *stack, size_t len)
{
	int	*array;
	int	i;
	int	n;

	i = 0;
	array = malloc(sizeof(int) * len);
	if (!array)
		return (0);
	while (i < len)
	{
		array[i] = stack->val;
		i++;
		stack = stack->next;
	}
	n = sizeof(array) / sizeof(array[0]);
	printf("i: %d\n", i);
	printf("n: %d\n", n);
	return (n);
}

t_stack	*ft_create_node(int num)
{
	t_stack	*node;

	node = malloc(sizeof(*node));
	if (!node)
		return (NULL);
	node->val = num;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	ft_insert_before_head(t_stack *head, t_stack *node)
{
	if (!head || !node)
		return ;
	node->prev = head->prev;
	node->next = head;
}

void	ft_insert_after_head(t_stack *head, t_stack *node)
{
	if (!head || !node)
		return ;
	node->prev = head;
	node->next = head->next;
}

int main(int argc, char *argv[])
{
	t_stack a;
	// t_stack b;
	int		n;
	int		i;
	int		**array;

	i = 1;
	a = NULL;
	if (argc >= 2)
	{
		
		while (argc)
		{
			
		}	
	}
}