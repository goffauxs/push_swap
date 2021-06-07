/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoffaux <sgoffaux@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 11:30:42 by sgoffaux          #+#    #+#             */
/*   Updated: 2021/06/07 14:13:56 by sgoffaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static void	ft_quicksort_recursive(int array[], int low, int high)
{
	int	pi;

	if (low < high)
	{
		pi = ft_partition(array, low, high);
		ft_quicksort_recursive(array, low, pi - 1);
		ft_quicksort_recursive(array, pi + 1, high);
	}
}

static void	ft_replace_indices(t_node *head, int *array, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < len)
		{
			if (head->val == array[j])
			{
				head->val = j;
				break ;
			}
			j++;
		}
		i++;
		head = head->next;
	}
}

void	ft_quicksort_stack(t_stack *a)
{
	size_t	i;
	int		*array;
	t_node	*head;

	i = 0;
	head = a->head;
	array = malloc(sizeof(int) * a->len);
	if (!array)
		return ;
	while (i < a->len)
	{
		array[i] = head->val;
		i++;
		head = head->next;
	}
	ft_quicksort_recursive(array, 0, a->len - 1);
	ft_replace_indices(head, array, a->len);
	free(array);
}
