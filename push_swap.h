/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 00:14:24 by user42            #+#    #+#             */
/*   Updated: 2021/07/13 02:20:48 by salimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

/* 
** Structure de données des éléments
*/

typedef struct      s_elem
{
	int nb;
	struct s_elem	*prev;
	struct s_elem	*next;
}					t_elem;

/*
** Structure de données des stacks
*/

typedef struct      s_content
{
	t_elem	*first;
	t_elem	*last;
	int size;
	int	mediane;
}                   t_content;

/*
** Structure des stacks
*/

typedef struct		s_stacks
{
    t_content a;
    t_content b;
    int       size;
}					t_stacks;

t_stacks stacks;
init_stacks(&stacks);
stacks.a.first->nb;

int	a;
int	*b;

a = 42;
*b = 42;

#endif