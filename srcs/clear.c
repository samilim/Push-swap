/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 23:19:54 by salimon           #+#    #+#             */
/*   Updated: 2022/04/15 23:30:18 by salimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	delete_node(struct s_elem **head_ref)
{
	t_elem	*tmp;

	tmp = (*head_ref);
	(*head_ref) = (*head_ref)->next;
	free(tmp);
}

void	clear_list(t_stack *stack)
{
	t_elem	*tmp;

	while (stack->head != NULL)
	{
		tmp = stack->head->next;
		free(stack->head);
		stack->head = tmp;
	}
	if (stack->head != NULL)
		free(stack->head);
	stack->head = NULL;
}
