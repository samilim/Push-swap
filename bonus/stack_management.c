/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 23:15:31 by salimon           #+#    #+#             */
/*   Updated: 2022/04/17 16:05:15 by salimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* Push en haut de la stack */
int push(struct s_elem** head_ref, long long int new_data)
{
    struct s_elem* new_node;

    new_node = (struct s_elem*)malloc(sizeof(struct s_elem));
	if(new_node == NULL)
		return (0);
    new_node->nb = new_data;
    new_node->next = (*head_ref);
    new_node->prev = NULL;
 
    /* change prev of head node to new node */
    if ((*head_ref) != NULL)
        (*head_ref)->prev = new_node;
 
    /* move the head to point to the new node */
    (*head_ref) = new_node;
	return (1);
}

/* Appends a new node at the end  */
int append(/*t_datas *datas, */struct s_elem** head_ref, struct s_elem** last_ref, long long int new_data)
{
    struct s_elem* new_node;

    new_node = (struct s_elem*)malloc(sizeof(struct s_elem));
	if(new_node == NULL)
		return (0);
    *last_ref = *head_ref;
    new_node->nb = new_data;
 
    /* This new node is going to be the last node, so
          make next of it as NULL*/
	new_node->next = NULL;
 
    /* If the Linked List is empty, then make the new
          node as head */
    if (*head_ref == NULL)
    {
        new_node->prev = NULL;
        *head_ref = new_node;
        (*last_ref) = new_node;
        return (1);
    }

    /* Else traverse till the last node */
    while ((*last_ref)->next != NULL)
        (*last_ref) = (*last_ref)->next;
 
    /* Change the next of last node */
    (*last_ref)->next = new_node;
 
    /* Make last node as previous of new node */
    new_node->prev = *last_ref;
    new_node->next = NULL;//
    (*last_ref) = new_node;
    return (1);
}