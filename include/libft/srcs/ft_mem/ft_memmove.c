/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 16:08:29 by fgranger          #+#    #+#             */
/*   Updated: 2022/11/12 16:34:28 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

   NAME         
   memmove - copy memory area
   SYNOPSIS         
#include <string.h>
void *memmove(void *dest, const void *src, size_t n);
DESCRIPTION         
The memmove() function copies n bytes from memory area src to
memory area dest.  The memory areas may overlap: copying takes
place as though the bytes in src are first copied into a
temporary array that does not overlap src or dest, and the bytes
are then copied from the temporary array to dest.
RETURN VALUE         
The memmove() function returns a pointer to dest.
*/

#include "../../includes/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	if (!dest && !src)
		return (NULL);
	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (d > s)
		while (n--)
			d[n] = s[n];
	else
		while (n--)
			*d++ = *s++;
	return (dest);
}
