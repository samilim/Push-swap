/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 18:50:33 by salimon           #+#    #+#             */
/*   Updated: 2021/01/09 15:42:19 by salimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int     ft_strncmp(const char *s1, const char *s2, size_t n)
{
    unsigned int i;
    unsigned char *cs1;
    unsigned char *cs2;

    i = 0;
    cs1 = (unsigned char *)s1;
    cs2 = (unsigned char *)s2;
    if (n == 0)
        return (0);
    while (i < n && cs1[i] == cs2[i] && cs1[i] != '\0' && cs2[i] != '\0')
        i++;
    return(cs1[i] - cs2[i]);
}