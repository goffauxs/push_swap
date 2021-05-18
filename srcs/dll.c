/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoffaux <sgoffaux@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 11:32:05 by sgoffaux          #+#    #+#             */
/*   Updated: 2021/05/18 14:37:30 by sgoffaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

t_node	*ft_create_node(int num, int first_node)
{
	t_node	*node;

	node = malloc(sizeof(*node));
	if (!node)
		return (NULL);
	node->val = num;
	if (first_node)
	{
		node->next = node;
		node->prev = node;
	}
	else
	{
		node->next = NULL;
		node->prev = NULL;
	}
	return (node);
}

void	ft_insert_before_head(t_node *head, t_node *node)
{
	if (!head || !node)
		return ;
	node->prev = head->prev;
	node->next = head;
	if (node->next)
		node->next->prev = node;
	if (node->prev)
		node->prev->next = node;
}

void	ft_insert_after_head(t_node *head, t_node *node)
{
	if (!head || !node)
		return ;
	node->prev = head;
	node->next = head->next;
	if (node->next)
		node->next->prev = node;
	if (node->prev)
		node->prev->next = node;
}

t_node	*ft_free_node(t_node *node)
{
	t_node	*tmp;

	tmp = node;
	if (node->prev)
		node->prev->next = node->next;
	if (node->next)
	{
		node->next->prev = node->prev;
		node = node->next;
	}
	else
		node = NULL;
	free(tmp);
	return (node);
}

void	ft_print_dll(t_node *head)
{
	t_node *tmp;

	if (head)
	{
		printf("%d\n", head->val);
		if (head->next)
		{
			tmp = head->next;
			while (tmp != head)
			{
				printf("%d\n", tmp->val);
				tmp = tmp->next;
			}
		}
	}
}