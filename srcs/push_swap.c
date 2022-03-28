/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 00:14:06 by user42            #+#    #+#             */
/*   Updated: 2022/03/28 05:12:45 by salimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	*empty_stack(void)
{
	return (NULL);
}

/* 
	Push all int in the tab in a
	Given a reference (pointer to pointer) to the head
	of a DLL and an int, appends a new node at the end  */
void	init_a(t_datas *datas)
{
	datas->a.head = NULL;
	/* 1. allocate node */
    struct s_elem	*new_node;
    new_node = (struct t_elem*)malloc(sizeof(struct s_elem));
 
    datas->a.last = datas->a.head; /* used in step 5*/
 
    /* 2. put in the data  */
    new_node->nb = datas->tab[0];

    /* 3. This new node is going to be the last node, so
          make next of it as NULL*/
    new_node->next = NULL;
 
    /* 4. If the Linked List is empty, then make the new
          node as head */
    if (datas->a.head == NULL)
	{
        new_node->prev = NULL;
        datas->a.head = new_node;
        return;
    }
 
    /* 5. Else traverse till the last node */
    while (datas->a.last->next != NULL)
        datas->a.last = datas->a.last->next;
 
    /* 6. Change the next of last node */
    datas->a.last->next = new_node;
 
    /* 7. Make last node as previous of new node */
    new_node->prev = datas->a.last;
    return;
}

void    push_swap()
{
}

int		manage_args(int argc, char **argv, t_datas *datas)
{
	int i;
	struct t_elem* head = NULL;

	i = 1;
	if (argc == 2) //cas str
	{
		if (check_error(datas, 1)) //check si str full chiffres
			return (error_case(3));
		datas->tab = atoi_args(argc, ft_split(argv[1], ' ')); // fragmente la str et place les int dans un tab d'int
	}
	else //cas ints ; place tous les arguments dans un tableau d'int
	{
		datas->tab = malloc(sizeof(int) * argc - 1);
		if (!(datas->tab))
			return (error_case(4));
		while (i < (argc - 1))
			*(datas->tab)++ = argv[i++];
	}
	if (check_error(datas, 2)) //check si full int
		return (error_case(2));
	free (datas->tab);
	return (0);
}

int main(int argc, char **argv)
{
	t_datas datas;

	if (argc < 2)
		return (error_case(1));
	if (manage_args(argc, argv, &datas) > 0)
		return (1);
	//datas.b.head = NULL;
	ft_pa(&datas);
	//ANALYSER A (voir quelle strat adopter)
	//TRIER (appliquer la strat)
	//push_swap(&datas);
	//free
	return (0);
}
