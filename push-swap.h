/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push-swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 17:55:42 by salimon           #+#    #+#             */
/*   Updated: 2021/05/23 05:03:08 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct		s_pile_a
{
    void			*content;
    struct s_pile_a	*next;

}					t_pile_a;

typedef struct		s_pile_b
{
	void			*content;
    struct s_pile_b	*next;
}					t_pile_b;


#endif