/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoffaux <sgoffaux@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 11:30:42 by sgoffaux          #+#    #+#             */
/*   Updated: 2021/05/19 14:17:51 by sgoffaux         ###   ########.fr       */
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

int	ft_get_midpoint(t_node *head, size_t len)
{
	int		*array;
	size_t	i;
	int		midpoint;

	i = 0;
	array = malloc(sizeof(int) * len);
	if (!array)
		return (0);
	while (i < len)
	{
		array[i] = head->val;
		i++;
		head = head->next;
	}
	ft_quicksort_recursive(array, 0, len - 1);
	midpoint = array[len / 2];
	free(array);
	return (midpoint);
}
