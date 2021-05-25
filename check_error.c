/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 05:12:28 by user42            #+#    #+#             */
/*   Updated: 2021/05/25 05:18:04 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push-swap.h"

int		check_duplicates(int argc, char **argv)
{
	while (argc >= 0)
	{
		/* parcoure les args*/
		if (/* found duplicate*/)
			return (1);
		argc--;
	}
	return (0);
}

int		check_not_integer(int argc, char **argv)
{
	
}

int		check_error(int argc, char **argv)
{
	if (/*argc trop grand ||*/check_duplicates(argv, argc) || check_not_integer(argv, argc))
	{
		write (1, "Error\n", 6);
		return (1);
	}
/*error : param non int ou doublon et si instructions n'existent pas pour bonus*/
}