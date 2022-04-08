/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 00:14:24 by user42            #+#    #+#             */
/*   Updated: 2022/04/08 17:06:33 by salimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
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
	struct s_elem	*head; //**
	struct s_elem	*last;
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
	long long int		*tab;
	int		argc;
	char	**argv;
	int		nb_elem;
}					t_datas;

int		check_error(t_datas *datas);
int		check_str(t_datas *datas, char **tab);
int		count_elem(char **nbs);
int		error_case(t_datas *datas, unsigned int error_code);
long long int		*atoi_args(t_datas *datas, char **nbs);
void	ft_pa(t_datas *datas);

#endif