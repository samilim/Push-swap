/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 00:14:24 by user42            #+#    #+#             */
/*   Updated: 2022/03/20 14:21:06 by salimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

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

typedef struct      s_stack
{
	t_elem	*first;
	t_elem	*last;
	int size;
	int	mediane;
}                   t_stack;

/*
** Structure des stacks
*/

typedef struct		s_datas
{
    t_stack a;
    t_stack b;
	int		*tab;
	int		argc;
	char	**argv;
}					t_datas;

int		check_error(t_datas *datas);

#endif