/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 00:14:06 by user42            #+#    #+#             */
/*   Updated: 2022/03/26 01:22:26 by salimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	*empty_stack(void)
{
	return (NULL);
}

/* Given a reference (pointer to pointer) to the head
   of a DLL and an int, appends a new node at the end  */
void	init_a(t_datas *datas)
{
	/* 1. allocate node */
    struct t_elem* new_node;
    new_node = malloc(sizeof(t_elem));
 
    struct t_elem* last = datas->a.head; /* used in step 5*/
 
    /* 2. put in the data  */
    new_node->nb = datas->tab[0];
 
    /* 3. This new node is going to be the last node, so
          make next of it as NULL*/
    new_node->next = NULL;
 
    /* 4. If the Linked List is empty, then make the new
          node as head */
    if (*head_ref == NULL) {
        new_node->prev = NULL;
        *head_ref = new_node;
        return;
    }
 
    /* 5. Else traverse till the last node */
    while (last->next != NULL)
        last = last->next;
 
    /* 6. Change the next of last node */
    last->next = new_node;
 
    /* 7. Make last node as previous of new node */
    new_node->prev = last;
 
    return;
} 

void    push_swap()
{
}

int		manage_args(int argc, char **argv, t_datas *datas)
{
	int i;

	i = 1;
	if (argc == 2) //cas str
	{
		if (check_error(datas)) //check str (full int)
			return (error_case());
		datas->tab = atoi_args(argc, ft_split(argv[1], ' '));
	}
	else //cas ints
	{
		if (check_error(datas)) //check si full int
			return (error_case());
		datas->tab = malloc(sizeof(int) * argc - 1);
		if (!(datas->tab))
			return (error_case());
		while (i < (argc - 1))
			*(datas->tab)++ = argv[i++];
	}
	init_a(&datas);
	free (datas->tab);
	return (1);
}

int main(int argc, char **argv)
{
	t_datas datas;
	
	datas.a.head = NULL;
	datas.b.head = NULL;
	init_a(&datas);
	ft_pa(&datas);

// 	if (argc < 2)
// 		return (error_case());
// 	if (!manage_args(argc, argv, &datas))
// 		return (0);
// 	//ANALYSER A (voir quelle strat adopter)
// 	//TRIER (appliquer la strat)
// 	push_swap(&datas);
// 	//free
	return (0);
}
