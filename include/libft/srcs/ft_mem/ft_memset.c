/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 16:08:36 by fgranger          #+#    #+#             */
/*   Updated: 2022/11/12 16:34:47 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

   NAME         
   memset - fill memory with a constant byte
   SYNOPSIS         
#include <string.h>
void *memset(void *s, int c, size_t n);
DESCRIPTION         
The memset() function fills the first n bytes of the memory area
pointed to by s with the constant byte c.
RETURN VALUE         
The memset() function returns a pointer to the memory area s.

*/

#include "../../includes/libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
		((unsigned char *)s)[i++] = c;
	return (s);
}
