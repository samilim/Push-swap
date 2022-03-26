/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 00:14:24 by user42            #+#    #+#             */
/*   Updated: 2022/03/26 07:13:11 by salimon          ###   ########.fr       */
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
	struct s_elem	**head;
	struct s_elem	**last;
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

int		check_error(t_datas *datas, unsigned int type_arg);
void	ft_pa(t_datas *datas);

#endif
yassharm