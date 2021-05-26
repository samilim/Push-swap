/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push-swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 17:55:42 by salimon           #+#    #+#             */
/*   Updated: 2021/05/26 02:10:18 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct		s_stack_a
{
    int			        elem;
    struct s_stack_a	*next;

}					t_stack_a;

typedef struct		s_stack_b
{
	int					elem;
    struct s_stack_b	*next;
}					t_stack_b;

#endif