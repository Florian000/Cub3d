/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 16:08:24 by fgranger          #+#    #+#             */
/*   Updated: 2022/11/12 16:34:09 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

   NAME         
   memcpy - copy memory area
   SYNOPSIS         
#include <string.h>
void *memcpy(void *restrict dest, const void *restrict src, size_t n);
DESCRIPTION         
The memcpy() function copies n bytes from memory area src to
memory area dest.  The memory areas must not overlap.  Use
memmove(3) if the memory areas do overlap.
RETURN VALUE         
The memcpy() function returns a pointer to dest.

*/

#include "../../includes/libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (!dest && !src)
		return (0);
	i = 0;
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}
