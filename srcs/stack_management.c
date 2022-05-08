/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 23:15:31 by salimon           #+#    #+#             */
/*   Updated: 2022/05/08 04:55:11 by salimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	push(struct s_elem **head_ref, long long int new_data)
{
	struct s_elem	*new_node;

	new_node = (struct s_elem *)malloc(sizeof(struct s_elem));
	if (new_node == NULL)
		return (0);
	new_node->nb = new_data;
	new_node->next = (*head_ref);
	new_node->prev = NULL;
	if ((*head_ref) != NULL)
		(*head_ref)->prev = new_node;
	(*head_ref) = new_node;
	return (1);
}

int	append(struct s_elem **head_ref,
struct s_elem **last_ref, long long int new_data)
{
	struct s_elem	*new_node;

	new_node = (struct s_elem *)malloc(sizeof(struct s_elem));
	if (new_node == NULL)
		return (0);
	*last_ref = *head_ref;
	new_node->nb = new_data;
	new_node->next = NULL;
	if (*head_ref == NULL)
	{
		new_node->prev = NULL;
		*head_ref = new_node;
		(*last_ref) = new_node;
		return (1);
	}
	while ((*last_ref)->next != NULL)
		(*last_ref) = (*last_ref)->next;
	(*last_ref)->next = new_node;
	new_node->prev = *last_ref;
	new_node->next = NULL;
	(*last_ref) = new_node;
	return (1);
}

/* Check if the stac is sorted */
int check_sort(t_stack stack)
{
	t_elem *tmp;

	tmp = stack.head;
	while (tmp->next != NULL)
	{
		if (tmp->nb > tmp->next->nb)
			return (0);
		tmp = tmp->next;
	}
	// printf("a is sorted\n");
	return (1);
}